#ifndef __UNDIRECTED_GRAPH__
#define __UNDIRECTED_GRAPH__
#include "Edge.h"
#include "Vertex.hpp"
#include <vector>
#include <fstream>

#include <iostream>
using std::cout;
using std::endl;

template<class Tp>
class Vertex;

class Edge;

// Adjacency multi-list
template<class Tp>
class Undirected_Graph
{
    friend class Edge;
    friend class Vertex<Tp>;
    using size_t = unsigned long long;

private:
    std::vector<Vertex<Tp>> vertexList;

public:
    Undirected_Graph(const std::vector<Tp>& vertexData, std::ifstream& edgeData);
    ~Undirected_Graph();
    void addToGraph(Edge* edge);
};

template<class Tp>
Undirected_Graph<Tp>::
Undirected_Graph(const std::vector<Tp>& vertexData,
                 std::ifstream& edgeData)
: vertexList()
{
    // TODO: Init vertexlist
    for(auto& i : vertexData){
        vertexList.push_back(Vertex<Tp>(i));
    }

    // Excepion: Cannot open file or file is empty;
    if(!edgeData || edgeData.eof()){
        throw "Initial data is invalid!";
    }

    // TODO: Link each vertex by edges.

    while(!edgeData.eof()){
        // Get edge's information from file
        size_t i, j, weight;// The indecies of 2 vertecies that connected by the edge.

        edgeData >> i;
        if(i > vertexList.size() - 1) throw "Index Overflow";
        Vertex<Tp>& vi{vertexList[j]};

        // edgeData >> weight;

        edgeData >> j;
        if(j > vertexList.size() - 1) throw "Index Overflow";
        Vertex<Tp>& vj{vertexList[j]};

        auto newEdge{new Edge(i, j)};
        
        // Link to graph
        addToGraph(newEdge);
    }
    // Test
        for(auto& i : vertexList){
            Edge* ptr{i.firstEdge};
            cout << i.data << ": ";
            while(ptr){
                cout << ptr->ivex << ptr->jvex << ' ';
                ptr = ptr->inext;
            }
            cout << endl;
        }
}
template<class Tp>
void Undirected_Graph<Tp>::addToGraph(Edge* edge){
    Vertex<Tp>& vi{vertexList[edge->ivex]};
    Vertex<Tp>& vj{vertexList[edge->jvex]};

    // Add to the tail of edge list.
    auto vi_edgeListTail{vi.firstEdge};
    if(!vi_edgeListTail){
        vi.firstEdge = edge;
    }else{
        while(vi_edgeListTail->inext){
            vi_edgeListTail = vi_edgeListTail->inext;
            }
        vi_edgeListTail->inext = edge;
    }

    auto vj_edgeListTail{vj.firstEdge};
    if(!vj_edgeListTail){
        vj.firstEdge = edge;
    }else{
        while(vj_edgeListTail->jnext){
            vj_edgeListTail = vj_edgeListTail->jnext;
        }

        vj_edgeListTail->jnext = edge;
    }
}

template<class Tp>
Undirected_Graph<Tp>::~Undirected_Graph()
{
}

#endif