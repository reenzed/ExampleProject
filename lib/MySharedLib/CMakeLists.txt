cmake_minimum_required(VERSION 3.14)
project(MySharedLib LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(${PROJECT_NAME} SHARED mylib.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION 1.0 SOVERSION 1)

if (WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES CXX_VISIBILITY_PRESET hidden)
    target_compile_definitions(${PROJECT_NAME} PRIVATE MY_SHARED_LIB_BUILD)
    install(TARGETS ${PROJECT_NAME} 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES mylib.h DESTINATION include)
