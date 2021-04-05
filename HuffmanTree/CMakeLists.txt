# Minimum CMake version required
cmake_minimum_required(VERSION 3.0.0)
project(HuffmanCoding VERSION 1.0.0)

# Project version
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)

include(CTest)
enable_testing()

# Add subdirectories, without this, the file cannot be found.
include_directories(src include rsrc)

# add_subdirectory(src)

# Store all the source files'names as a list in the variable 'SRC'
aux_source_directory(. SRC)
aux_source_directory(./src LIB)

# Complie
add_library(HuffmanTree ${LIB})

add_executable(HuffmanCoding ${SRC})

# Link
# Head
target_include_directories(HuffmanCoding PUBLIC ./include)
target_link_libraries(HuffmanCoding Huffmantree)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# include(CPack)
