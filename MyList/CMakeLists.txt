project(MyList CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

# Collecting files
aux_source_directory(./src SRC)
include_directories(./include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_library(List INTERFACE)
target_include_directories(List INTERFACE ${PROJECT_SOURCE_DIR}/include)

add_executable(Demo ./main.cpp)

target_link_libraries(Demo PRIVATE List)