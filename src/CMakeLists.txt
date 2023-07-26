cmake_minimum_required(VERSION 3.22.1)

project(DOENGINE)


add_executable(${PROJECT_NAME} 
               main.cpp 
               Window/Window.cpp
               Timer/FPSManager.cpp
               Tilemap/Tilemap.cpp
               Texture/Texture.cpp
               GameState/GameStateManager.cpp
               GameState/TestState.cpp
               GameState/PlatformState.cpp
               GameObject/GameObject.cpp
             
               GameObject/Camera.cpp
               GameObject/BackgroundObject.cpp
               Font/TTFText.cpp
               Event/Event.cpp
               Drawable/Geometric.cpp
               Drawable/PrimitiveGraphics.cpp
               Drawable/Canvas.cpp
               algorithm/sort.cpp
               includes/defines.h
               includes/Camera.h
               includes/Event.h
               includes/DOEngine.h
               includes/EventHandler.h
               includes/FPSManager.h
               includes/GameObject.h
               includes/GameState.h
               includes/GameStateManager.h
               includes/Geometric.h
               includes/Grids.h
               includes/LinkList.h
               includes/sort.h
               includes/Sprite.h
               includes/StandardFuncs.h
               includes/TestState.h
               includes/Texture.h
               includes/Tile.h
               includes/Tilemap.h
               includes/UDPPacket.h
               includes/Vector.h
               includes/Window.h
               )

include_directories(${CMAKE_SOURCE_DIR}/includes)


target_link_libraries(${PROJECT_NAME}  PRIVATE SDL2 SDL2_ttf SDL2_image SDL2_mixer)


install(TARGETS ${PROJECT_NAME} DESTINATION /home/afl/Desktop/doengine )