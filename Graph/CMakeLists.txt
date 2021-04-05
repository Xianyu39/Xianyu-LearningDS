cmake_minimum_required(VERSION 3.1.0)
project(Graph)

# Collect file
aux_source_directory(./src SRC)
include_directories(./include)

# Generate lib
add_library(Graph SHARED ${SRC})

# Header file
target_include_directories(Graph 
PUBLIC 
./include)

# Compile
add_executable(Main main.cpp)

# Link
target_link_libraries(Main Graph)
