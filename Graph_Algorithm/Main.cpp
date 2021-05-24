#include "UGraph.hpp"

int main(){
    try{
        // Next 2 lines were using to test.
        int i = 9;
        // std::cin >> i;

        std::ifstream file("D:\\pspro\\C_C++_pro\\DataStructure_Algorithms\\Graph_Algorithm\\rsrc\\Dt.txt");
        char s[]{"ABCDEFGHIJKMLNOPQRSTU"};
        UGraph<char> ug(s, i, file, UGraph<char>::Mode::UN_DIRECTED);
        std::vector<size_t> vec;
        ug.BreadthFirstTraverse(0);
        cout << endl;
        ug.DepthFirstTraverse();
        // ug.Prim();
        cout << endl;
        // ug.Kruskal();
        // ug.Dijstra(3, vec);
        
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    catch(const char* msg){
        std::cerr << "ErrorFound: " << msg << std::endl;
    }
    
    return 0;
}