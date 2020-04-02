cmake_minimum_required(VERSION 3.15)
project(PrimerProyecto C)

set(CMAKE_C_STANDARD 11)

ADD_LIBRARY(regex STATIC IMPORTED)
SET_TARGET_PROPERTIES(regex PROPERTIES IMPORTED_LOCATION C:/msys64/mingw64/lib/libsystre.dll.a)

add_executable(PrimerProyecto main.c)