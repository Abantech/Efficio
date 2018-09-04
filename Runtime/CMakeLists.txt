execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Runtime 
	src/EfficioStarted
	src/Engine
	src/HistoricalFrameCollection
	src/InputRecognitionEngine
	src/Message
	src/MessageBus
	src/PerformanceManager
	src/AssetManager
	)

target_link_libraries (Efficio.Runtime LINK_PUBLIC 
	Efficio.Core 
	Efficio.Models.Body
	Efficio.Assets.LeapMotion 
	#Efficio.Assets.IntelRealSense 
	Efficio.Recognition.Body)

target_include_directories (Efficio.Runtime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)