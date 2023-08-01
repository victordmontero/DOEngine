cmake_minimum_required(VERSION 3.22.1)

project(DOENGINE)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} 
               main.cpp 
               Window/Window.cpp
               Timer/FPSManager.cpp
               Tilemap/Tilemap.cpp
               Texture/Texture.cpp
               GameState/GameStateManager.cpp
          
      
               GameObject/GameObject.cpp
             
             
               Font/TTFText.cpp
               Event/Event.cpp
               Drawable/Canvas.cpp
              
               includes/defines.h
               includes/Camera.h
               includes/Event.h
               includes/DOEngine.h
               includes/EventHandler.h
               includes/FPSManager.h
               includes/GameObject.h
               includes/GameState.h
               includes/GameStateManager.h
               includes/Grids.h
               includes/LinkList.h
               includes/sort.h
               includes/Sprite.h
               includes/StandardFuncs.h
               
               includes/Texture.h
               includes/Tile.h
               includes/Tilemap.h
               includes/UDPPacket.h
               includes/Vector.h
               includes/Window.h

# Sample APP
               sample/CanvasTestState.cpp
               sample/MatrixTestState.cpp
               sample/SortedState.cpp
               )

include_directories(${CMAKE_SOURCE_DIR}/includes)


target_link_libraries(${PROJECT_NAME}  PRIVATE SDL2 SDL2_ttf SDL2_image SDL2_mixer)


install(TARGETS ${PROJECT_NAME} DESTINATION /home/afl/Desktop/doengine )