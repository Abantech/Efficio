cmake_minimum_required(VERSION 3.7)
project (Efficio)

add_subdirectory (Core)
add_subdirectory (Runtime)

add_executable (Test Console.cpp)
target_link_libraries (Test LINK_PUBLIC Efficio.Runtime)

install (TARGETS Test DESTINATION bin)