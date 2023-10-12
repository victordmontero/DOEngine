
cmake_minimum_required(VERSION 2.13)
project(Doengine_tests)

include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${CMAKE_SOURCE_DIR}/test/)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)

target_link_libraries(GTest::GTest INTERFACE gtest_main gmock_main)

if(DOENGINE_COVERAGE)
    message("Compiling with coverage flags")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
endif()

add_executable(${PROJECT_NAME}
    units/utUtils.cpp
    units/utLinkList.cpp
    mocks/GameStateMock.h
    mocks/FPSManagerMock.h
    mocks/CameraMock.h
    mocks/MusicHandlerMock.h
    mocks/ParticleMock.h
    mocks/RendererMock.h
    mocks/FontMock.h
    mocks/EventHandlerMock.h
    mocks/GameObjectMock.h
    mocks/AbstractWindowMock.h
    mocks/GameStateManagerMock.h
    testmain.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    GTest::GTest
    # Another library
)

add_test(NAME testapp_gtest
    COMMAND ${PROJECT_NAME})
