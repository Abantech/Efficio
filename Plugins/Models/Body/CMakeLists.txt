cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Models.Body
			src/Finger.cpp
			src/Joint.cpp
			src/Hand.cpp
			src/HandData.cpp)

target_link_libraries (Efficio.Models.Body LINK_PUBLIC Efficio.Core)

target_include_directories (Efficio.Models.Body PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)