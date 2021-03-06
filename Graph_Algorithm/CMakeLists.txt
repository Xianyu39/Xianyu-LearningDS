cmake_minimum_required(VERSION 3.1.0)
project(Graph_Algorithm)

# # Debug(GDB)
# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
# SET(CMAKE_CXX_FLAGS_RELEASE "ENV{CXXFLAGS} -O3 -Wall")

# Collect file
aux_source_directory(./src SRC)
include_directories(./include)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Generate lib
add_library(Graph_Algorithms SHARED ${SRC} ${PROJECT_SOURCE_DIR}/include/UGraph.hpp)

# Header file
target_include_directories(Graph_Algorithms
PUBLIC 
./include)

# Compile
add_executable(Main main.cpp)

# Link
target_link_libraries(Main Graph_Algorithms)