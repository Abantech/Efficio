cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Models.Spatial
			src/GPSData.cpp
			src/Spatial3DData.cpp
			src/Spatial2DData.cpp)

target_link_libraries (Efficio.Models.Spatial LINK_PUBLIC Efficio.Core)

target_include_directories (Efficio.Models.Spatial PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)