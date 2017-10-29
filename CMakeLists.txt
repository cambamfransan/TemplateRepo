cmake_minimum_required(VERSION 3.2.2)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
project(TemplateRepo)
include (version.cmake)

set(CMAKE_CXX_STANDARD 14)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

add_subdirectory(Shared)
add_subdirectory(Executable)
add_subdirectory(Playground)

