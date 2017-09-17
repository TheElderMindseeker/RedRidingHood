cmake_minimum_required(VERSION 3.8)
project(RedRidingHood)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        static_object/StaticAgent.cpp
        static_object/StaticAgent.hpp
        agent/Agent.cpp
        agent/Agent.hpp
        map/Map.cpp
        map/Map.hpp
        map/MapGenerator.cpp
        map/MapGenerator.hpp
        static_object/Wolf.cpp
        static_object/Wolf.hpp
        static_object/Bear.cpp
        static_object/Bear.hpp
        static_object/Woodcutter.cpp
        static_object/Woodcutter.hpp
        static_object/Granny.cpp
        static_object/Granny.hpp
        agent/AStarHood.cpp
        agent/AStarHood.hpp
        agent/BacktrackHood.cpp
        agent/BacktrackHood.hpp)
add_executable(RedRidingHood ${SOURCE_FILES})