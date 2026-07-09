
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