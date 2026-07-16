message(STATUS "DOENGINE: copying assets to build dir")
file(COPY ${ASSETS_DIR}
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
