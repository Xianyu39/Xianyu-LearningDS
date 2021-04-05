#include <iostream>
#include <unordered_map>
using namespace std;

template<class Obj, size_t Num>
class Graph{
private:
    int **Adjacent_Matrix;
    unordered_map<Obj, size_t> Vertex;

public:
    Graph(){
        // Allocate memory
        Adjacent_Matrix = new int *[Num];
        for (auto &row : Adjacent_Matrix){
            row = new int[Num];
        }

        // Initial
        for (auto &i : Adjacent_Matrix){
            for (auto &j : i){
                j = 0;
            }
        }
    }
    ~Graph(){
        if (Num != 0){
            for (auto &row : Adjacent_Matrix){
                delete[] row;
            }
        }
    }
    void Add_Vertex(const Obj &val){
        static size_t ix{0};
        Vertex[val] = ix++;
    }

    //无向图连接节点
    void Connect(Obj &lhs, Obj &rhs, int weight = 1){
        auto x{Vertex[lhs]}, y{Vertex[rhs]};
        Adjacent_Matrix[x][y] = Adjacent_Matrix[y][x] = weight;
    }

    //有向图连接节点
    void Direct_Connect(Obj &lhs, Obj &rhs, int weight = 1){
        auto x{Vertex[lhs]}, y{Vertex[rhs]};
        Adjacent_Matrix[x][y] = weight;
    }

    void test(){
        for (auto &i : Adjacent_Matrix){
            for (auto &j : i){
                cout << j << ' ';
            }
            cout << endl;
        }
    }
};

int main(){
    Graph<char, 10> g;
    g.Add_Vertex('A');
    g.Add_Vertex('B');
    g.Add_Vertex('C');
    g.Add_Vertex('D');
    g.Add_Vertex('E');
    g.Add_Vertex('F');
    g.Add_Vertex('G');

    g.test();

    return 0;
}