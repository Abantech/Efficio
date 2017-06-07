cmake_minimum_required(VERSION 3.7)
set(PROJECT_SOURCE_DIR  src)

execute_process(COMMAND doxygen docs/default.doxygen
				WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Core SHARED 
	src/Connected.cpp
	src/Connecting.cpp
	src/Disconnected.cpp
	src/Disconnecting.cpp
	src/DiscreteEvent.cpp
	src/Event.cpp
	src/Faulted.cpp
	src/Frame.cpp
	src/IRecognitionProcessor
	src/Sensor.cpp
	src/SensorEvent.cpp
	src/SensorInformation.cpp)

target_include_directories (Efficio.Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)