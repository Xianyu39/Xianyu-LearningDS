#include "Graph.h"
#include <iostream>
#include <fstream>
// Demo

int main(){
    std::ifstream in(Path + "Initial.txt");
    Graph g(in);
    return 0;
}