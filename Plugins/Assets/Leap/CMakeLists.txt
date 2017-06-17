cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Assets.LeapMotion
			src/LeapMotion.cpp
			src/LeapMotionSensor.cpp)

target_link_libraries (Efficio.Assets.LeapMotion LINK_PUBLIC Efficio.Core)

target_include_directories (Efficio.Assets.LeapMotion  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)