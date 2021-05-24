project(Undirected_Graph)
cmake_minimum_required(VERSION 3.1.0)

# Collect file
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
aux_source_directory(./src SOURCE)
include_directories(./include)

# Generate library and exe
add_library(Undirected_Graph SHARED ${SOURCE})
add_executable(main ./main.cpp)

# Link 
target_link_libraries(main Undirected_Graph)