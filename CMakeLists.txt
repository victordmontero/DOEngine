cmake_minimum_required(VERSION 3.22.1)

project(DOENGINE
    VERSION 0.1.0
    LANGUAGES CXX
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(FetchContent)

option(DOENGINE_COVERAGE "Compile with coverage flags" OFF)
option(DOENGINE_TESTS "Compiles and runs tests" OFF)
option(DOENGINE_SAMPLES "Compiles samples" ON)
option(DOENGINE_INSTALL "Generate install rules and package config for DOENGINE" ON)
option(DOENGINE_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

if(DOENGINE_COVERAGE)
    include(cmake-module/CodeCoverage.cmake)
endif()

# set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(DOENGINE_PREFERED_LANGUAGE 17)
set(CMAKE_CXX_STANDARD ${DOENGINE_PREFERED_LANGUAGE})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Respect a build type the user/generator already chose; only default to Debug
# for single-config generators that haven't set one.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(FETCH_SDL_FROM_GIT false)
set(FETCH_GLM_FROM_GIT true)
set(BUILD_SAMPLE_ACTIVE false)

set(SDL2IMAGE_INSTALL OFF)
set(BUILD_SHARED_LIBS FALSE)
set(SDL2_DISABLE_INSTALL OFF)
set(SDL2TTF_VENDORED TRUE)

set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)

# ---------------------------------------------------------------------------
# Dependencies
# ---------------------------------------------------------------------------

# OpenGL is always required, regardless of where SDL comes from.
find_package(OpenGL REQUIRED)

if(FETCH_SDL_FROM_GIT)
    include(cmake-module/fetchSDL3ProjectFromSource.cmake)
else()
    message(STATUS "DOENGINE: using system-installed SDL2 (FETCH_SDL_FROM_GIT=OFF)")
    find_package(SDL2 REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_mixer REQUIRED)
endif()

if(FETCH_GLM_FROM_GIT)
    include(cmake-module/fetchGLMProjectFromSource.cmake)
else()
    message(STATUS "DOENGINE: using system-installed GLM (FETCH_GLM_FROM_GIT=OFF)")
    find_package(glm REQUIRED)
endif()

# Needed by the optional "-sample" target (zip support for asset packing).
# Only probed when the full sample build is enabled, so a missing libzip
# doesn't break the default build.
if(BUILD_SAMPLE_ACTIVE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBZIP REQUIRED IMPORTED_TARGET libzip)
endif()

if(DOENGINE_TESTS)
    #enable_testing()
    #add_subdirectory(src/test)
endif()

include_directories(${CMAKE_SOURCE_DIR}/includes)

set(DOENGINE_SRC
    includes/DS.h
    includes/OpenglLoader.h
    includes/WindowManager.h
    includes/Renderer.h
    includes/Logger.h
    src/Application/OpenglLoader.cpp
    src/Application/Geometric.cpp
    src/Application/Logger.cpp
    src/Application/opengl_decls.cpp
    src/Application/opengl_decls.h
    src/Application/SDLOpenglWindow.cpp
    src/Application/SDLOpenglRenderer.cpp
    src/Application/SDLWindowManager.cpp
    src/Application/WindowManager.cpp
    src/Application/SDLWindowManager.h
    src/Application/SDLRenderer.cpp
    src/Application/SDLRenderer.h
    src/Application/SDLTTFText.h
    src/Application/SDLTTFText.cpp
    src/Application/Timer.cpp
    src/Application/Application.cpp
    src/Application/StringUtils.cpp
    src/Timer/FPSManager.cpp
    src/GameState/GameStateManager.cpp
    src/Timer/FPSManager.cpp
    src/Tilemap/Tilemap.cpp
    src/Tilemap/TileMapEditor.cpp
    src/Texture/Texture.cpp
    src/Event/SDLMouse.cpp
    src/Event/SDLKeyboard.cpp
    src/Music/SDLMusicHandler.cpp
    src/Music/SDLSoundHandler.cpp
    src/Event/SDLJoypad.cpp
    src/Music/SDLMusicHandler.cpp
    src/GameObject/GameObject.cpp
    src/Font/TTFText.cpp
    src/Font/FontCache.cpp
    src/Event/Event.cpp
    src/Event/EventHandler.cpp
    src/Drawable/Gui.cpp
    src/Drawable/UI.cpp
    src/Drawable/TextField.cpp
    src/Application/GameState.cpp
    src/Application/Camera.cpp
    src/Application/SDLTexture.cpp
    src/Application/SDLTexture.h
    src/Drawable/GameObject.cpp
    src/Drawable/Draggable.cpp
    src/Drawable/DraggableGameObject.cpp
    src/Drawable/SelectionRect.cpp
    src/Drawable/MessageBox.cpp
    includes/NativeStructs.h
    includes/Geometric.h
    includes/Color.h
    includes/defines.h
    includes/NothingNess.h
    includes/AnimatedSprite.h
    includes/TTFText.h
    includes/FontCache.h
    includes/Camera.h
    includes/Event.h
    includes/DOEngine.h
    includes/DOEngine_SDL_includes.h
    includes/EventHandler.h
    includes/FPSManager.h
    includes/GameObject.h
    includes/GameState.h
    includes/GameStateManager.h
    includes/Grids.h
    includes/LinkList.h
    includes/sort.h
    includes/Sprite.h
    includes/Utils.h
    includes/Texture.h
    includes/Tile.h
    includes/Tilemap.h
    includes/TileMapEditor.h
    includes/UDPPacket.h
    includes/Vector.h
    includes/Application.h
    includes/Mouse.h
    includes/Keyboard.h
    includes/Joypad.h
    includes/MusicHandler.h
    includes/SDLMusicHandler.h
    includes/SDLSoundHandler.h
    includes/UI.h
    includes/Draggable.h
    includes/DraggableGameObject.h
    includes/SelectionRect.h
    includes/SpriteOffset.h
    includes/TextField.h
    includes/MessageBox.h
)

# ---------------------------------------------------------------------------
# Library target
# (must exist before target_include_directories / add_subdirectory reference it)
# ---------------------------------------------------------------------------
add_library(${PROJECT_NAME}
    ${DOENGINE_SRC}
)

add_library(DOENGINE::DOENGINE ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/includes>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
)

if(DOENGINE_WARNINGS_AS_ERRORS)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
    endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()

set(DOENGINE_LIBRARIES )

if(FETCH_SDL_FROM_GIT)
    set(DOENGINE_LIBRARIES ${DOENGINE_LIBRARIES}
        SDL2::SDL2
        SDL2::SDL2main
        SDL2_ttf::SDL2_ttf
        SDL2_image::SDL2_image
        SDL2_mixer
        OpenGL::GL
    )
else()
    set(DOENGINE_LIBRARIES ${DOENGINE_LIBRARIES}
        SDL2::SDL2
        SDL2::SDL2main
        SDL2_ttf::SDL2_ttf
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
        OpenGL::GL
    )
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC ${DOENGINE_LIBRARIES})

message(STATUS "DOENGINE: copying assets to build dir")
file(COPY ${ASSETS_DIR}
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# ---------------------------------------------------------------------------
# Install rules / package config
# ---------------------------------------------------------------------------
if(DOENGINE_INSTALL)
    install(
        TARGETS ${PROJECT_NAME}
        EXPORT DOENGINETargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

    install(
        DIRECTORY includes/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    )

    install(
        DIRECTORY assets/
        DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
    )

    install(
        EXPORT DOENGINETargets
        FILE DOENGINETargets.cmake
        NAMESPACE DOENGINE::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DOENGINE
    )

    # Minimal package config so downstream projects can do
    # find_package(DOENGINE CONFIG REQUIRED) and link DOENGINE::DOENGINE.
    set(DOENGINE_CONFIG_IN ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfig.cmake.in)
    file(WRITE ${DOENGINE_CONFIG_IN}
"@PACKAGE_INIT@\n\ninclude(CMakeFindDependencyMacro)\nfind_dependency(OpenGL)\nfind_dependency(SDL2)\nfind_dependency(SDL2_ttf)\nfind_dependency(SDL2_image)\nfind_dependency(SDL2_mixer)\nfind_dependency(glm)\n\ninclude(\"\${CMAKE_CURRENT_LIST_DIR}/DOENGINETargets.cmake\")\n"
    )

    configure_package_config_file(
        ${DOENGINE_CONFIG_IN}
        ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DOENGINE
    )

    write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    install(
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfig.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DOENGINE
    )
endif()

# install(TARGETS ${PROJECT_NAME} DESTINATION /home/afl/Desktop/doengine )

# ---------------------------------------------------------------------------
# Samples
# (added after the library target exists, since samples link against it)
# ---------------------------------------------------------------------------
if(DOENGINE_SAMPLES)
    add_subdirectory(sample)
endif()

if(${BUILD_SAMPLE_ACTIVE})
#add_executable(${PROJECT_NAME}-sample
#   sample/ignored_main.cpp 
#)
add_executable(${PROJECT_NAME}-pong-sample
   sample/pong/SimplePong.cpp 
)

add_executable(${PROJECT_NAME}-SpaceInvader-sample
   sample/SpaceInvader/SpaceInvader.cpp
)

add_executable(${PROJECT_NAME}-Tetris-sample
   sample/tetris/Tetris.cpp
)

add_executable(${PROJECT_NAME}-MusicPlayer-sample
   sample/MusicPlayer/MusicPlayer.cpp
)
add_executable(BattleSpawn
   sample/BattleSpawn/BattleSpawn.cpp
)
add_executable(PacmanClone
   sample/Pacman/Pacman.cpp
)

add_executable(BattleCityRecreation
   sample/BattleCityRecreation/BattleCityRecreation.cpp
)

add_executable(Tetris
   sample/tetris/Tetris.cpp
)

add_executable(SideScroller
    sample/SideScroller/SideScroller.cpp
)

# to build sample needs 
# Zip support, ubuntu sudo apt-get install libzip-dev
#target_link_libraries(${PROJECT_NAME}-sample PRIVATE
#    ${PROJECT_NAME}
#    ${DOENGINE_LIBRARIES}
#    PkgConfig::LIBZIP
#)

target_link_libraries(${PROJECT_NAME}-pong-sample PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}-SpaceInvader-sample PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}-Tetris-sample PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}-MusicPlayer-sample PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)

target_link_libraries(BattleSpawn PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)

target_link_libraries(PacmanClone PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)


target_link_libraries(BattleCityRecreation PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)

target_link_libraries(Tetris PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)


target_link_libraries(SideScroller PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)
endif()