cmake_minimum_required(VERSION 3.14)
project(MyModuleLib LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(${PROJECT_NAME} MODULE mymodule.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION 1.0 SOVERSION 1)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES mymodule.h DESTINATION include)
