# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(Breakout)

#
add_executable(Breakout src/breakout.cpp)

# Especificar onde estao os header files
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(model src/model/model.cpp)
target_link_libraries(Breakout model)
add_library(view src/view/view.cpp)
target_link_libraries(Breakout view)
add_library(controller src/controller/controller.cpp)
target_link_libraries(Breakout controller)
add_library(tijolo src/model/tijolo.cpp)
target_link_libraries(Breakout tijolo)


# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS "-std=c++0x")

# Bibliotecas linkadas externamente
target_link_libraries(Breakout SDL2)
target_link_libraries(Breakout SDL2_image)
