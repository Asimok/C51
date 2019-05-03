cmake_minimum_required(VERSION 3.14)
project(serial)

set(CMAKE_CXX_STANDARD 14)

add_executable(serial main.cpp serial_led.c fasongzifu.c back.c zifuchuan.c)