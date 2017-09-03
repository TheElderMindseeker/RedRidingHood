cmake_minimum_required(VERSION 3.8)
project(RedRidingHood)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp static_object/StaticObject.cpp static_object/StaticObject.hpp agent/Agent.cpp agent/Agent.hpp Map.cpp Map.hpp MapGenerator.cpp MapGenerator.hpp static_object/Wolf.cpp static_object/Wolf.hpp)
add_executable(RedRidingHood ${SOURCE_FILES})