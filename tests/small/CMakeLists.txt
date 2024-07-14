cmake_minimum_required(VERSION 3.14)
project(SmallTests LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} example_tests.cpp MockBase.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${catch2_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${trompeloeil_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${PROJECT_NAME} PRIVATE trompeloeil)

target_link_libraries(${PROJECT_NAME} PRIVATE MyStaticLib)

include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME})

