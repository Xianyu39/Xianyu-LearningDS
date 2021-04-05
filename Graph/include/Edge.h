#ifndef __EDGE_H__
#define __EDGE_H__
#include "Alias.h"
#include "Graph.h"

// Directed edge, and has weight
class Edge : public Alias
{
    friend class Graph;
private:
    // The vertex that the edge comes from.
    size_t tailVtx;

    // The vertex that the edge comes to.
    size_t headVtx;

    Edge* headList;
    Edge* tailList;

    double weight;

public:
    Edge(size_t Head_Vertex, size_t Tail_Vertex, Edge* Head_List=nullptr, Edge* Tail_list=nullptr);
    ~Edge();
};

Edge ::Edge(size_t Head_Vertex, size_t Tail_Vertex, Edge* Head_List, Edge* Tail_list)
:headList(Head_List), tailList(Tail_list), headVtx(Head_Vertex), tailVtx(Tail_Vertex)
{}

Edge ::~Edge()
{}
#endif