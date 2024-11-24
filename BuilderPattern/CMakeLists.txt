cmake_minimum_required(VERSION 3.17)
project(CompositeBuilder)

set(CMAKE_CXX_STANDARD 20)

add_executable(CompositeBuilder main.cpp src/Person.h src/PersonBuilderBase.h src/PersonBuilder.h src/PersonAddressBuilder.h src/PersonJobBuilder.h src/Person.cpp src/PersonBuilderBase.cpp)