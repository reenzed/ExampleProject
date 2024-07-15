cmake_minimum_required(VERSION 3.21)
project(ExampleProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

add_executable(ExampleApp app/main.cpp)
target_link_libraries(ExampleApp PRIVATE MyStaticLib)
target_link_libraries(ExampleApp PRIVATE MySharedLib)
target_include_directories(ExampleApp PRIVATE ${MySharedLib_SOURCE_DIR})
target_include_directories(ExampleApp PRIVATE ${MyModuleLib_SOURCE_DIR})

if (WIN32)
    # copy MySharedLib.dll to ExampleApp.exe folder
    # 1. must be used as administrator -> "cmake --install ."
    # install(TARGETS ExampleApp RUNTIME DESTINATION bin)
    # install(FILES $<TARGET_FILE:MySharedLib> DESTINATION bin)
    # 2. add_custom_command
    add_custom_command(TARGET ExampleApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:MySharedLib>
    $<TARGET_FILE_DIR:ExampleApp>)

    add_custom_command(TARGET ExampleApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:MyModuleLib>
    $<TARGET_FILE_DIR:ExampleApp>)
endif()

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
