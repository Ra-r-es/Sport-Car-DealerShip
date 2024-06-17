cmake_minimum_required(VERSION 3.27)
project(Proiect_Masini_Sport)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proiect_Masini_Sport
        MasiniSport.cpp
        MasiniSport.h
        main.cpp
        COUPE.cpp
        HOTHATCH.h
        CABRIO.h
        SUPERSPORT.h
        HOTHATCH.cpp
        HOTHATCH.cpp
        CABRIO.cpp
        SUPERSPORT.cpp)
