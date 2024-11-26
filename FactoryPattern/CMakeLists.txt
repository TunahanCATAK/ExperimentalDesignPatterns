cmake_minimum_required(VERSION 3.17)
project(NestedFactory)

set(CMAKE_CXX_STANDARD 20)

add_executable(NestedFactory main.cpp src/Wall.h src/SolidWall.h src/WallFactory.h)