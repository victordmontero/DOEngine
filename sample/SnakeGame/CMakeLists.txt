cmake_minimum_required(VERSION 3.22.1)

project(SnakeGame)

include_directories(DOSAMPLE PRIVATE ../../includes)
include_directories(MUSIC_SAMPLE PRIVATE ../../includes)

add_executable(${PROJECT_NAME}
    SnakeGame.cpp
)

file(COPY ${ASSETS_DIR}
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE
    doengine
    SDL2-static
    SDL2_image
    SDL2_ttf
    SDL2_mixer
)
