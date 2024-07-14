cmake_minimum_required(VERSION 3.14)
project(ExampleTests LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.6.0
)
FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(
  trompeloeil
  GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
  GIT_TAG        v47
)
FetchContent_MakeAvailable(trompeloeil)

add_subdirectory(small)  #unit
add_subdirectory(middle) #integration
#add_subdirectory(large) #acceptance
