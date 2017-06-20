cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Models.AudioVisual
			src/ImageData
			src/Image)

target_link_libraries (Efficio.Models.AudioVisual LINK_PUBLIC Efficio.Core)

target_include_directories (Efficio.Models.AudioVisual PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)