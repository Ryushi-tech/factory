cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftrapv -g")

add_executable(main main)
add_executable(tle tle)
add_executable(generate generate)
