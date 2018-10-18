cmake_minimum_required(VERSION 3.12)
project(myTunes C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(myTunes
        driver.c
        linked_list.c
        linked_list.h
        music.c
        music.h)
