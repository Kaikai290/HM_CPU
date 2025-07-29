cmake_minimum_required(VERSION 3.30)

project(HM_CPU VERSION 0.1 LANGUAGES C CXX)

enable_testing()

add_executable(Accumulator
  main.cpp
  bit.cpp 
  logicgates.cpp)

add_test(NAME AccumulatorRuns COMMAND cd build Accumulator.exe)
