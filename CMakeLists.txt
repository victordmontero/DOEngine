cmake_minimum_required(VERSION 3.20)
project(DOEngine VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Folder layout expected:
#   ${DOENGINE_SDL_EXTERNAL_DIR}/SDL/         (has its own CMakeLists.txt)
#   ${DOENGINE_SDL_EXTERNAL_DIR}/SDL_image/
#   ${DOENGINE_SDL_EXTERNAL_DIR}/SDL_ttf/
#   ${DOENGINE_SDL_EXTERNAL_DIR}/SDL_mixer/
#   ${DOENGINE_SDL_EXTERNAL_DIR}/SDL_net/
set(DOENGINE_SDL_EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/doengine-shared/SDL2" CACHE PATH
    "Folder containing local SDL2 + family source trees")

option(DOENGINE_WITH_IMAGE "Bundle SDL2_image" ON)
option(DOENGINE_WITH_TTF   "Bundle SDL2_ttf"   ON)
option(DOENGINE_WITH_MIXER "Bundle SDL2_mixer" ON)
option(DOENGINE_WITH_NET   "Bundle SDL2_net"   ON)
option(DOENGINE_INSTALL_SYSTEM_SDL "Install SDL2 family into the system when built from source" ON)

include(GNUInstallDirs)

# Family is always built/used static -- it gets embedded into DOEngine.
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON  CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(SDL2_DISABLE_INSTALL ${DOENGINE_INSTALL_SYSTEM_SDL} CACHE BOOL "" FORCE)
if(DOENGINE_INSTALL_SYSTEM_SDL)
    set(SDL2_DISABLE_INSTALL OFF CACHE BOOL "" FORCE)
endif()
set(SDL2IMAGE_INSTALL ${DOENGINE_INSTALL_SYSTEM_SDL} CACHE BOOL "" FORCE)
set(SDL2TTF_INSTALL   ${DOENGINE_INSTALL_SYSTEM_SDL} CACHE BOOL "" FORCE)
set(SDL2MIXER_INSTALL ${DOENGINE_INSTALL_SYSTEM_SDL} CACHE BOOL "" FORCE)
set(SDL2NET_INSTALL   ${DOENGINE_INSTALL_SYSTEM_SDL} CACHE BOOL "" FORCE)

# Picks the first target name that actually exists out of several candidates
# (different SDL2 releases/build modes create different alias names).
function(doengine_resolve_target OUT_VAR)
    foreach(_cand ${ARGN})
        if(TARGET ${_cand})
            set(${OUT_VAR} ${_cand} PARENT_SCOPE)
            return()
        endif()
    endforeach()
    message(FATAL_ERROR "DOEngine: none of these targets exist: ${ARGN}")
endfunction()

# --- SDL2: use it if the system already has it, else build+install from external/ ---
find_package(SDL2 QUIET CONFIG)
if(NOT SDL2_FOUND)
    message(STATUS "DOEngine: building SDL2 from ${DOENGINE_SDL_EXTERNAL_DIR}/SDL")
    add_subdirectory(${DOENGINE_SDL_EXTERNAL_DIR}/SDL ${CMAKE_BINARY_DIR}/_sdl2_build)
else()
    message(STATUS "DOEngine: using system SDL2 (${SDL2_DIR})")
endif()
doengine_resolve_target(_sdl2_target SDL2::SDL2-static SDL2-static SDL2::SDL2 SDL2)
set(sdl2_SOURCE_DIR ${DOENGINE_SDL_EXTERNAL_DIR}/SDL)

set(_family ${_sdl2_target})

macro(doengine_add_family NAME OPT SUBDIR)
    if(${OPT})
        find_package(${NAME} QUIET CONFIG)
        if(NOT ${NAME}_FOUND)
            message(STATUS "DOEngine: building ${NAME} from ${DOENGINE_SDL_EXTERNAL_DIR}/${SUBDIR}")
            add_subdirectory(${DOENGINE_SDL_EXTERNAL_DIR}/${SUBDIR} ${CMAKE_BINARY_DIR}/_${SUBDIR}_build)
        else()
            message(STATUS "DOEngine: using system ${NAME}")
        endif()
        doengine_resolve_target(_resolved
            ${NAME}::${NAME}-static ${NAME}-static ${NAME}::${NAME} ${NAME})
        list(APPEND _family ${_resolved})
    endif()
endmacro()

doengine_add_family(SDL2_image DOENGINE_WITH_IMAGE SDL_image)
doengine_add_family(SDL2_ttf   DOENGINE_WITH_TTF   SDL_ttf)
doengine_add_family(SDL2_mixer DOENGINE_WITH_MIXER SDL_mixer)
doengine_add_family(SDL2_net   DOENGINE_WITH_NET   SDL_net)

# --- DOEngine itself ---
file(GLOB_RECURSE DOENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

add_library(DOEngine STATIC ${DOENGINE_SOURCES})
add_library(DOEngine::DOEngine ALIAS DOEngine)

target_include_directories(DOEngine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
        $<BUILD_INTERFACE:${sdl2_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:includes>
)

target_link_libraries(DOEngine PRIVATE ${_family})

# --- Merge DOEngine.a + every family .a (and their vendored sub-deps:
#     ogg, opus, opusfile, xmp, wavpack, ...) object-by-object into one
#     monolithic static library via ar. ---
set(_monolith ${CMAKE_BINARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}DOEngine${CMAKE_STATIC_LIBRARY_SUFFIX})
set(_merge_script ${CMAKE_BINARY_DIR}/merge_static.cmake)
file(WRITE ${_merge_script}
"file(GLOB_RECURSE _ARCHIVES \"${CMAKE_BINARY_DIR}/*${CMAKE_STATIC_LIBRARY_SUFFIX}\")\n"
"list(REMOVE_ITEM _ARCHIVES \"${_monolith}\")\n"
"set(_MERGE_DIR \"${CMAKE_BINARY_DIR}/_merge_objs\")\n"
"file(REMOVE_RECURSE \"\${_MERGE_DIR}\")\n"
"file(MAKE_DIRECTORY \"\${_MERGE_DIR}\")\n"
"set(_i 0)\n"
"foreach(_lib \${_ARCHIVES})\n"
"    set(_d \"\${_MERGE_DIR}/lib\${_i}\")\n"
"    file(MAKE_DIRECTORY \"\${_d}\")\n"
"    execute_process(COMMAND \"${CMAKE_AR}\" x \"\${_lib}\" WORKING_DIRECTORY \"\${_d}\")\n"
"    math(EXPR _i \"\${_i}+1\")\n"
"endforeach()\n"
"file(GLOB_RECURSE _OBJS \"\${_MERGE_DIR}/*${CMAKE_C_OUTPUT_EXTENSION}\")\n"
"file(REMOVE \"${_monolith}\")\n"
"execute_process(COMMAND \"${CMAKE_AR}\" rcs \"${_monolith}\" \${_OBJS})\n"
"execute_process(COMMAND \"${CMAKE_RANLIB}\" \"${_monolith}\")\n"
)

add_custom_command(TARGET DOEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -P ${_merge_script}
    COMMENT "Merging SDL2 family into monolithic ${_monolith}"
    VERBATIM
)

install(FILES ${_monolith}
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RENAME ${CMAKE_STATIC_LIBRARY_PREFIX}DOEngine${CMAKE_STATIC_LIBRARY_SUFFIX}
)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/includes/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)