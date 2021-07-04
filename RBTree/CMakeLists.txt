project(RedBlackTree)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(RBTree INTERFACE ${PROJECT_SOURCE_DIR}/include/RBTree.hpp)
target_include_directories(RBTree INTERFACE ${PROJECT_SOURCE_DIR}/include/RBTree.hpp)

add_executable(Demo ${PROJECT_SOURCE_DIR}/Main.cpp)
target_link_libraries(Demo INTERFACE RBTree)