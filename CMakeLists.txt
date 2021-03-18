cmake_minimum_required(VERSION 3.20)

project(heap_array LANGUAGES CXX)

# library
add_library(heap_array INTERFACE include/heap_array/array.hpp include/heap_array/array_type.hpp)

target_include_directories(heap_array INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# example
option(BUILD_EXAMPLE "Builds example" ON)

if (BUILD_EXAMPLE)
	# support folders in IDE's
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# select startup project
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT example)

	add_subdirectory(example)
endif()
