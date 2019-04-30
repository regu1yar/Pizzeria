cmake_minimum_required(VERSION 2.6)
project(Pizzeria)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Pizzeria main.cpp Pizza.h Staff.h Pizzeria.h PizzeriaTest.h PtrTest.h)
target_link_libraries(Pizzeria ${GTEST_LIBRARIES} pthread)
