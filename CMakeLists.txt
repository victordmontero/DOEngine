cmake_minimum_required(VERSION 3.22.1)

project(DOENGINE)

option(DOENGINE_COVERAGE "Compile with coverage flags" FALSE)
option(DOENGINE_TESTS "Compiles and runs tests" FALSE)

if(DOENGINE_COVERAGE)
    include(cmake-module/CodeCoverage.cmake)
endif()

# set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(FETCH_SDL_FROM_GIT true)
set(DOENGINE_PREFERED_LANGUAGE 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD ${DOENGINE_PREFERED_LANGUAGE})

set(SDL2IMAGE_INSTALL OFF)
set(BUILD_SHARED_LIBS FALSE)
set(SDL2_DISABLE_INSTALL OFF)
set(SDL2TTF_VENDORED TRUE)

if(DOENGINE_TESTS)
    enable_testing()
    add_subdirectory(src/test)
endif()

if(FETCH_SDL_FROM_GIT)
   include(cmake-module/fetchSDLProjectFromSource.cmake)
else()
    message("WARNING: SDL Would the Machine Installed Version")
endif()

include_directories(${CMAKE_SOURCE_DIR}/includes)

add_library(${PROJECT_NAME}
    src/Timer/FPSManager.cpp
    src/Tilemap/Tilemap.cpp
    src/Texture/Texture.cpp
    src/GameState/GameStateManager.cpp
    src/GameObject/GameObject.cpp
    src/Font/TTFText.cpp
    src/Event/Event.cpp
    src/Drawable/Canvas.cpp
    src/Drawable/SDLRenderer.cpp
    src/Event/SDLMouse.cpp
    src/Event/SDLKeyboard.cpp
    src/Event/SDLJoypad.cpp

    includes/defines.h
    includes/abstract/Camera.h
    includes/Event.h
    includes/DOEngine.h
    includes/DOEngine_SDL_includes.h
    includes/abstract/EventHandler.h
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
    includes/UDPPacket.h
    includes/Vector.h
    includes/abstract/devices/Mouse.h
    includes/abstract/devices/Keyboard.h
    includes/abstract/devices/Joypad.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_ttf SDL2_image
    SDL2_mixer)



set(DOENGINE_LIBRARIES )
if(FETCH_SDL_FROM_GIT)
  set(DOENGINE_LIBRARIES ${DOENGINE_LIBRARIES} 
        SDL2::SDL2
        SDL2::SDL2main
        SDL2_ttf SDL2_image
        SDL2_mixer
  )    
else()
    set(DOENGINE_LIBRARIES ${DOENGINE_LIBRARIES} 
        SDL2
        SDL2main
        SDL2_ttf SDL2_image
        SDL2_mixer
    )  
endif()

add_executable(${PROJECT_NAME}-sample
   sample/ignored_main.cpp 
)

target_link_libraries(${PROJECT_NAME}-sample PRIVATE
    ${PROJECT_NAME}
    ${DOENGINE_LIBRARIES}
)

# install(TARGETS ${PROJECT_NAME} DESTINATION /home/afl/Desktop/doengine )
