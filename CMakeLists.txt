cmake_minimum_required(VERSION 3.8)
project(RedRidingHood)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp StaticObject.cpp StaticObject.hpp Agent.cpp Agent.hpp Map.cpp Map.hpp CellData.cpp CellData.hpp)
add_executable(RedRidingHood ${SOURCE_FILES})