cmake_minimum_required(VERSION 3.0.0)
project(HashTable)
set(LANGUAGE CXX)

# collecting
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Compiling
add_library(HashTable SHARED ${SRC})
add_executable(Demo ${PROJECT_SOURCE_DIR}/Demo.cpp)

# Linking
target_include_directories(Demo PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(Demo HashTable)