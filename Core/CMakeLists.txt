cmake_minimum_required(VERSION 3.7)
set(PROJECT_SOURCE_DIR  src)

add_library(Efficio.Core SHARED 
	src/Sensor.cpp
	src/Event.cpp)

target_include_directories (Efficio.Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)