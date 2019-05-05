cmake_minimum_required(VERSION 3.14)
project(serial)

set(CMAKE_CXX_STANDARD 14)

add_executable(serial main.cpp 串口实验/serial_led.c 串口实验/fasongzifu.c 串口实验/back.c 串口实验/zifuchuan.c 串口实验/serial_led_search.c 液晶板实验/xianshizifuchuan.c)