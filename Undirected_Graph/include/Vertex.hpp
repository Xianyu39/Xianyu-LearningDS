#ifndef __VERTEX_H__
#define __VERTEX_H__
#include "Edge.h"

template<class Tp>
class Undirected_Graph;

template<class Tp>
class Vertex
{
    friend class Undirected_Graph<Tp>;

private:
    Tp data;
    Edge* firstEdge;
    
public:
    Vertex(const Tp& Data, Edge* edge = nullptr): data(Data), firstEdge(edge){}
    ~Vertex(){}
};

#endif