cmake_minimum_required(VERSION 3.31)
project(rootcalc)

set(CMAKE_CXX_STANDARD 23)

add_executable(rootcalc main.cpp
        RootTableGenerator.h
        RootTableGenerator.cpp
        NumberUtil.cpp
        NumberUtil.h
        RootCalculator.cpp
        RootCalculator.h
        Random.h
        Benchmark.cpp
        Benchmark.h
        Timer.cpp
        Timer.h
        AverageCalculator.cpp
        AverageCalculator.h)
