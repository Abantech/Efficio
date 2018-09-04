cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND doxygen docs/default.doxygen WORKING_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Efficio.Assets.LeapMotion
			src/LeapMotion
			src/LeapMotionSensor)

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
    set (ENVIRONMENT "x86")
else ()
    set (ENVIRONMENT "x64")
endif ()

include_directories($ENV{LEAP_SDK}\\include)
# Search for library
FIND_LIBRARY(LEAP_LIBRARY
			NAMES Leap 
			PATHS $ENV{LEAP_SDK}\\lib\\${ENVIRONMENT})

configure_file($ENV{LEAP_SDK}\\lib\\${ENVIRONMENT}\\Leap.dll
                    ${CMAKE_BINARY_DIR}/Leap.dll
                    COPYONLY)

target_link_libraries (Efficio.Assets.LeapMotion LINK_PUBLIC Efficio.Core Efficio.Models.Body Efficio.Models.AudioVisual ${LEAP_LIBRARY})

target_include_directories (Efficio.Assets.LeapMotion  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)