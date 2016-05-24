cmake_minimum_required(VERSION 3.5)
project(zso-zad3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES inode.c file.c super.c dir.c ialloc.c ioctl.c)

include_directories(~/Pobrane/linux-4.1.18)

add_executable(untitled ${SOURCE_FILES})