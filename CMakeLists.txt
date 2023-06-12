cmake_minimum_required (VERSION 3.20.0)

# enable verbose makefile generation
set(CMAKE_VERBOSE_MAKEFILE on)

# Execute conan from cmake.
set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES ConanProvider.cmake)

# OS/Toolchain specific rules.
if (UNIX)
    include(GNUToolchain.cmake)
endif()

# Must be defined after includes/toolchains.
project (Example LANGUAGES CXX)

# Define standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# enable ctest
enable_testing()

find_package(fmt REQUIRED)

# main source directory
include_directories(src/main/include)
add_subdirectory(src/main/cpp)

# build test is SKIP_BUILD_TESTS is not true.
if (NOT SKIP_BUILD_TESTS)
    # calls conan supplied files to discover GTest library.
    find_package(GTest REQUIRED)

    # test source directory
    include_directories(src/test/include)
    add_subdirectory(src/test/cpp)
    
    # NOTE: Example code to pull in and build git repo directly.
    # # Fetch GoogleTest from GIT
    # include(GoogleTest)
    # include(FetchContent)
    # FetchContent_Declare(
    # googletest
    # GIT_REPOSITORY https://github.com/google/googletest.git
    # GIT_TAG        release-1.12.1
    # )

    # # For Windows: Prevent overriding the parent project's compiler/linker settings
    # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # # So that GoogleTest does not get installed with this project
    # option(INSTALL_GTEST "Enable installation of googletest." OFF)

    # # Enable google test for use in project.
    # FetchContent_MakeAvailable(googletest)
endif()