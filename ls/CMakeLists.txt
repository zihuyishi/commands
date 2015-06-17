cmake_minimum_required(VERSION 3.1)
project(ls)

enable_testing()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings} -std=c++11")

add_subdirectory(pathCore)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp)
add_executable(ls ${SOURCE_FILES})
target_link_libraries(ls pathCore)

# add test

set(GMOCK_DIR "../thirdpart/gmock-1.7.0" CACHE PATH
    "The path to the GoogleMock test framework.")

add_subdirectory(${GMOCK_DIR} ${CMAKE_BINARY_DIR}/gmock)

include_directories(SYSTEM ${GMOCK_DIR}/gtest/include
                           ${GMOCK_DIR}/include)

add_executable(all_test unit_test/all_test.cpp unit_test/path_test.cpp)
target_link_libraries(all_test  pathCore
                                gmock_main)

add_test(all_test all_test)
