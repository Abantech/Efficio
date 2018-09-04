cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Core
			src/Asset.cpp
			src/Connected.cpp
			src/Connecting.cpp
			src/ContinuousEvent.cpp
			src/Disconnected.cpp
			src/Disconnecting.cpp
			src/DiscreteEvent.cpp
			src/Event.cpp
			src/Faulted.cpp
			src/Frame.cpp
			src/Sensor.cpp
			src/SensorEvent.cpp
			src/SensorInformation.cpp
			src/Vector2.cpp
			src/Vector3.cpp)

target_include_directories (Efficio.Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)