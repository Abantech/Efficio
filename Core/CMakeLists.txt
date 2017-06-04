cmake_minimum_required(VERSION 3.7)

add_library(Efficio.Core SHARED Test.cpp)

target_include_directories (Efficio.Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})