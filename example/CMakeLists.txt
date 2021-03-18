add_executable(example example.cpp)

target_link_libraries(example heap_array)

target_compile_features(example PRIVATE cxx_std_17)
set_target_properties(example PROPERTIES CXX_EXTENSIONS OFF)

if (MSVC)
	target_compile_options(example PRIVATE /W4)
else()
	target_compile_options(example PRIVATE -Wall -Wextra -Wpedantic)
endif()
