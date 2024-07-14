cmake_minimum_required(VERSION 3.14)
project(ExampleProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)


add_executable(ExampleApp app/main.cpp)
target_link_libraries(ExampleApp PRIVATE MyStaticLib)
target_link_libraries(ExampleApp PRIVATE MySharedLib)
target_include_directories(ExampleApp PRIVATE ${MySharedLib_SOURCE_DIR})
target_include_directories(ExampleApp PRIVATE ${MyModuleLib_SOURCE_DIR})

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
