cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftrapv -g")

add_executable(main main)
add_executable(Amain A/main)
add_executable(Bmain B/main)
add_executable(Cmain C/main)
add_executable(Dmain D/main)
add_executable(Emain E/main)
add_executable(Fmain F/main)
add_executable(Mmain Marathon/main)
add_executable(tle tle)
#add_executable(generate generate)
