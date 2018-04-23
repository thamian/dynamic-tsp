cmake_minimum_required(VERSION 2.6)
project(dynamic-tsp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        combination.cpp
        console.cpp
        controller.cpp
        convert.cpp
        distancematrix.cpp
        file.cpp
        libraryobject.cpp
        message.cpp
        travellingsalesmanproblem.cpp)
add_executable(dynamic-tsp ${SOURCE_FILES})
