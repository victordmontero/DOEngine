cmake_minimum_required(VERSION 3.22.1)

project(DOSAMPLE)

include_directories(DOSAMPLE PRIVATE ../includes)
include_directories(MUSIC_SAMPLE PRIVATE ../includes)

add_executable(DoSample
    main.cpp
)

add_executable(Music
    Music.cpp
)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/gymnopedie-1-erik-satie.mp3
        COMMAND echo Salsa 
                ${CMAKE_CURRENT_SOURCE_DIR}/assets/gymnopedie-1-erik-satie.mp3
                ${CMAKE_CURRENT_BINARY_DIR}/gymnopedie-1-erik-satie.mp3)
# target_link_options(DOSAMPLE PRIVATE
#     "LINKER:-static" -static-libgcc -static-libstdc++)


target_link_libraries(DoSample PRIVATE
    DOENGINE
    SDL2
    SDL2main
    SDL2_ttf SDL2_image
    SDL2_mixer)

target_link_libraries(Music PRIVATE
    DOENGINE
    SDL2
    SDL2main
    SDL2_ttf SDL2_image
    SDL2_mixer)
