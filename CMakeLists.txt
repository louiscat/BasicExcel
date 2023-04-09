cmake_minimum_required(VERSION 3.17)
project(BasicExcel)

set(CMAKE_CXX_STANDARD 14)

add_library(BasicExcel BasicExcel.cpp BasicExcel.hpp libExcel.cpp libExcel.h)