cmake_minimum_required(VERSION 2.8.4)
project(Kao)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_custom_target(Kao COMMAND make -C ${Kao_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

