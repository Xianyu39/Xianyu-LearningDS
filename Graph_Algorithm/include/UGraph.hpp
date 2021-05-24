#ifndef __UGRAPH_HPP__
#define __UGRAPH_HPP__
#include <vector>
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
using std::cout;
using std::endl;

static const double Infinity{99999.9};

template<typename Tp>
class UGraph
{
private:
    std::vector<Tp> Vertex;
    // Adjacent Matrix, Row is out, Colum is in.
    double ** Edge;
    size_t size;

public:
    static const unsigned int MAX{11};
    enum class Mode { DIRECTED, UN_DIRECTED };

    UGraph();
    UGraph(const Tp arr[], size_t num, std::ifstream& edge, Mode mode = Mode::UN_DIRECTED);
    ~UGraph();
    double*& operator[](size_t i) { 
        if (i > size - 1){
            throw "Index Overflow at [] operator.";
        }
        return Edge[i]; 
    }
    void BreadthFirstTraverse(size_t root = 0);
    void DepthFirstTraverse();
    void DFS(size_t root, std::vector<bool>& Visited);
    void Prim();
    void Kruskal();
    void Dijstra(size_t v1, std::vector<size_t>& shortestWay);
    // void Floyd();
};

template<typename Tp>
UGraph<Tp>::UGraph() : Vertex(), size(0)
{
    Edge = new double*[MAX];
    for (size_t i = 0; i < MAX; i++){
        Edge[i] = new double[10];
        for (size_t j = 0; j < MAX; j++){
            Edge[i][j] = 0;
        }
    }
}

template<typename Tp>
UGraph<Tp>::UGraph(const Tp arr[], size_t num, std::ifstream& edge, Mode mode) : Vertex(arr, arr + num), size(num)
{
    // Check
    if(size > MAX){
        throw "Too much vertexes is not suggested.";
    }

    // Allocate memory
    Edge = new double*[size];
    for (size_t i = 0; i < size; i++){
        Edge[i] = new double[10];
        for (size_t j = 0; j < size; j++){
            if(i == j)
                Edge[i][j] = 0;
            else
                Edge[i][j] = Infinity;
        }
    }

    // TODO Get edge data and connect the vertecies
    if (!edge || edge.eof()){
        throw "Initial file is invalid.";
    }
    
    size_t i{0};
    while (i++ < num) {
        double weight;
        size_t i, j;// Vertecies indecies
        edge >> i;
        edge >> weight;
        edge >> j;

        // Watch
        // cout << i << ' ' << weight << ' ' << j << endl;

        if (i > size - 1 || j > size - 1) { throw "Index overflow at constructor."; }
        switch (mode)
        {
        case Mode::UN_DIRECTED:
            Edge[j][i] = weight;
        case Mode::DIRECTED:
            Edge[i][j] = weight;
        default:
            break;
        }
    }

    edge.close();

    // //Test
    // for (size_t i = 0; i < size; i++){
    //     for (size_t j = 0; j < size; j++){
    //         if(Edge[i][j] != Infinity){
    //             cout << Edge[i][j] << ' ';
    //         }else{
    //             cout << "INF" << ' ';
    //         }
    //     }
    //     cout << endl;
    // }
    
}

template<typename Tp>
UGraph<Tp>::~UGraph(){
    for (size_t i = 0; i < size; i++)
    {
        delete[] Edge[i];
    }
    delete[] Edge;
}

template<typename Tp> void
UGraph<Tp>::BreadthFirstTraverse(size_t root){
    //Check
    if(root < 0 || root > size - 1){
        throw "Index overflow at BFS";
    }

    // Do some prepration
    enum Status{ VISITED, WILL_VISITED, NOT_FOUND_YET };
    Status visited[size];
    for (size_t i = 0; i < size; i++){
        visited[i] = NOT_FOUND_YET;
    }
    std::queue<size_t> neighbors;// All the vertexes on the edge of visited area;

    // Begin at root
    neighbors.push(root);
    while(!neighbors.empty()) {
        auto vtx{neighbors.front()};
        neighbors.pop();
        cout << Vertex[vtx] << ' ';
        visited[vtx] = VISITED;

        for(size_t i{0}; i < size; ++i){
            if(Edge[vtx][i] != 0 && Edge[vtx][i] != Infinity && visited[i] == NOT_FOUND_YET){
                neighbors.push(i);
                visited[i] = WILL_VISITED;
            }
        }
    }
}


template<typename Tp> void
UGraph<Tp>::DepthFirstTraverse(){
    // Initialize
    std::vector<bool> Visited;
    Visited.resize(size);
    for (size_t i = 0; i < size; i++)
    {
        Visited[i] = false;
    }

    //Traverse
    for (size_t i = 0; i < size; i++){
        if (!Visited[i]){
            DFS(i, Visited);
        }
    }  
}

template<typename Tp> void
UGraph<Tp>::DFS(size_t root, std::vector<bool>& Visited){
    cout << Vertex[root] << ' ';
    Visited[root] = true;
    for (size_t j{0}; j < size; ++j) {
        if(Edge[root][j] == 1 && j != root && !Visited[j]){
            DFS(j, Visited);
        }
    }
}

template<typename Tp> void
UGraph<Tp>::Prim(){
    // Initial.
    std::vector<double> Weight(size);// 每个点离集合的距离
    std::vector<size_t> MSTree(size);

    Weight[0] = 0;
    MSTree[0] = 0;
    for (size_t i = 1; i < size; i++){
        Weight[i] = Edge[0][i];
        MSTree[i] = 0;
    }

    for (size_t i = 1; i < size; i++)
    {
        // 找到距离这个集合最近的顶点
        double min{Infinity};
        size_t closest;
        for(size_t j{1}; j < size; ++j){
            if(Weight[j] && Weight[j] < min){
                min = Weight[j];
                closest = j;
            }
        }

        cout << closest << MSTree[closest] << ' ';

        // 加入集合内
        Weight[closest] = 0;

        // 重新计算顶点j到集合内的距离, 因为其他的之前已经算过一次了，所以只处理新加进去的这个顶点就行
        for(size_t j{1}; j<size; ++j){
            if(Weight[j] && Edge[closest][j] < Weight[j]){
                Weight[j] = Edge[closest][j];
                MSTree[j] = closest;
            }
        }
    }
    
}

struct Single_Edge
{
    size_t Vertex1;
    size_t Vertex2;
    double weight;

    Single_Edge(size_t V1, size_t V2, double Weight):Vertex1(V1), Vertex2(V2), weight(Weight){}
};


template<typename Tp> void
UGraph<Tp>::Kruskal(){
    /*Kruskal算法意在把图看作一片森林，每个顶点都是一棵树，搜索最短的边并把其连接的两棵树合并
    。如果发现两边顶点都属于同一棵树就不要合并，否则会形成环路。*/
    // Generate the edge array and sort it into increasing order by weight.
    std::vector<Single_Edge> edgeSet;
    for (size_t i = 0; i < size; i++){
        for(size_t j = 0; j < i; j++){
            if(Edge[i][j] != 0 && Edge[i][j] != Infinity){
                edgeSet.push_back(Single_Edge(i, j, Edge[i][j]));
                // cout << i << '-' << j << ' ' << Edge[i][j] << endl;
            }
        }
    }
    std::sort(edgeSet.begin(), edgeSet.end(), [](Single_Edge& a, Single_Edge& b)->bool{
        return a.weight<b.weight;
    });

    /* 使用双亲表示法建立一座森林以及一个寻源函数，
    数组下标对应节点，值对应双亲，根节点双亲为0，0号位置空开*/
    std::vector<size_t> forest;
    forest.push_back(0);
    for (size_t i = 0; i < size; i++) {
        forest.push_back(0);
    }
    
    for(auto& edge : edgeSet){
        // Find the root of the edge's 2 vertexes
        size_t root1 = edge.Vertex1;
        size_t root2 = edge.Vertex2;
        while(forest[root1] != 0){
            root1 = forest[root1];
        }
        while(forest[root2] != 0){
            root2 = forest[root2];
        }

        // if they are not belong to the same tree.
        if(root1 != root2){
            forest[root2] = root1;
            cout << edge.Vertex1 << edge.Vertex2 << ' ';
        }
    }
}

template<typename Tp> void
UGraph<Tp>::Dijstra(size_t v1,std::vector<size_t>& shortestWay){
    // Initialize
    shortestWay.clear();
    shortestWay.resize(size);
    for(auto& i : shortestWay){
        i = Infinity;
    }
    shortestWay[v1] = 0;

    // get shortest way
    for (size_t v = 0; v < size; v++){
        for (size_t e = 0; e < size; ++e){
            if (Edge[v][e] != 0 && Edge[v][e] + shortestWay[v] < shortestWay[e]){
                shortestWay[e] = Edge[v][e] + shortestWay[v];
            }
        }
    }

    //Test
    cout << endl;
    for(auto i : shortestWay){
        cout << i << ' ';
    }
}
#endif