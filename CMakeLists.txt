cmake_minimum_required(VERSION 3.20)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP main.cpp CSet.h ShapeFactory.h CNumberFactory.h Building.h Clock.h ClockAndDate.h Location.h Vehicle.h Shape.h)
