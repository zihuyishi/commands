cmake_minimum_required(VERSION 3.1)
project(ls)

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(pathCore)

set(SOURCE_FILES main.cpp)
add_executable(ls ${SOURCE_FILES})
target_link_libraries(ls pathCore)