
execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Recognition.Body
			src/HandRecognitionProcessor
			src/PinchEvent
			src/PointEvent
			src/FistEvent)

target_link_libraries (Efficio.Recognition.Body LINK_PUBLIC Efficio.Models.Body)

target_include_directories (Efficio.Recognition.Body PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)