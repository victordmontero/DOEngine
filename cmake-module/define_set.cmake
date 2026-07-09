message("Using set script")

# CMake 4 compatibility for older dependencies
if(CMAKE_VERSION VERSION_GREATER_EQUAL "4.0")
    set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(FetchContent)

option(DOENGINE_COVERAGE "Compile with coverage flags" OFF)
option(DOENGINE_TESTS "Compiles and runs tests" OFF)
option(DOENGINE_SAMPLES "Compiles samples" OFF)
option(DOENGINE_INSTALL "Generate install rules and package config for DOENGINE" ON)
option(DOENGINE_WARNINGS_AS_ERRORS "Treat all warnings as errors" ON)
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


set(FETCH_SDL_FROM_EXT_FOLDER true)
set(FETCH_SDL_FROM_GIT false)
set(FETCH_GLM_FROM_GIT true)
set(BUILD_SAMPLE_ACTIVE FALSE)
set(BUILD_SHARED_LIBS FALSE)
set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)