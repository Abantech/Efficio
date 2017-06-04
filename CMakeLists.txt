cmake_minimum_required(VERSION 3.7)
project (Efficio)

add_subdirectory (Core)

add_executable (Test Console.cpp)

target_link_libraries (Test LINK_PUBLIC Efficio.Core)

install (TARGETS Test DESTINATION bin)