execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Runtime 
	src/EfficioStarted.cpp
	src/Engine
	src/HistoricalFrameCollection.cpp
	src/InputRecognitionEngine)

target_link_libraries (Efficio.Runtime LINK_PUBLIC Efficio.Core Efficio.Models.Spatial)

target_include_directories (Efficio.Runtime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)