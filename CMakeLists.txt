# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(BreakoutServer)
project(Breakout)

#
add_executable(BreakoutServer src/breakoutServer.cpp)
add_executable(Breakout src/breakout.cpp)

# Especificar onde estao os header files
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(view src/view/view.cpp)
target_link_libraries(Breakout view)
target_link_libraries(BreakoutServer view)
add_library(controller src/controller/controller.cpp)
target_link_libraries(Breakout controller)
target_link_libraries(BreakoutServer controller)
add_library(tijolo src/model/tijolo.cpp)
target_link_libraries(Breakout tijolo)
target_link_libraries(BreakoutServer tijolo)
add_library(barra src/model/barra.cpp)
target_link_libraries(Breakout barra)
target_link_libraries(BreakoutServer barra)
add_library(bolinha src/model/bolinha.cpp)
target_link_libraries(Breakout bolinha)
target_link_libraries(BreakoutServer bolinha)
add_library(pontos src/model/pontos.cpp)
target_link_libraries(Breakout pontos)
target_link_libraries(BreakoutServer pontos)
add_library(vida src/model/vida.cpp)
target_link_libraries(Breakout vida)
target_link_libraries(BreakoutServer vida)
add_library(teclado src/model/teclado.cpp)
target_link_libraries(Breakout teclado)
target_link_libraries(BreakoutServer teclado)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS "-std=c++14")

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS filesystem regex) 

# Bibliotecas linkadas externamente
target_link_libraries(BreakoutServer SDL2)
target_link_libraries(BreakoutServer SDL2_image)
target_link_libraries(BreakoutServer SDL2_ttf)
target_link_libraries(BreakoutServer Boost::filesystem Boost::regex)
target_link_libraries(Breakout SDL2)
target_link_libraries(Breakout SDL2_image)
target_link_libraries(Breakout SDL2_ttf)
target_link_libraries(Breakout Boost::filesystem Boost::regex)
target_link_libraries(Breakout pthread)
target_link_libraries(BreakoutServer pthread)




