cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Assets.IntelRealSense
			src/RealSense.cpp
			src/RealSenseSensor.cpp)

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
    set (ENVIRONMENT "x64")
else ()
    set (ENVIRONMENT "x64")
endif ()

include_directories($ENV{RSSDK_DIR}\\include $ENV{RSSDK_DIR}\\include\\RealSense)
# Search for library
FIND_LIBRARY(RS_LIBRARY
			NAMES realsense2
			PATHS $ENV{RSSDK_DIR}\\lib\\${ENVIRONMENT})

configure_file($ENV{RSSDK_DIR}\\lib\\${ENVIRONMENT}\\realsense2.lib
                    ${CMAKE_BINARY_DIR}/Debug/realsense2.lib
                    COPYONLY)

target_link_libraries (Efficio.Assets.IntelRealSense LINK_PUBLIC Efficio.Core Efficio.Models.Body Efficio.Models.AudioVisual ${RS_LIBRARY})

target_include_directories (Efficio.Assets.IntelRealSense  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)