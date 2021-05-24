#include "Undirected_Graph.hpp"
#include <iostream>
using namespace std;

int main(){
    std::vector<char> vec({'A', 'B', 'C', 'D', 'E'});
    std::ifstream file("./../../rsrc/EdgeData.txt");
    try{
        Undirected_Graph<char> ug(vec, file);
    }
    catch(const char* s){
        cerr << s << endl;
        cout << s << endl;
    }

    return 0;
}