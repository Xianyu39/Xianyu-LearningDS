#ifndef __VERTEX_H__
#define __VERTEX_H__
#include "Edge.h"
#include "Alias.h"
#include "Graph.h"

// Basic element of graph
class Vertex: public Alias
{
    friend class Graph;
    friend bool operator==(const Vertex& a, const Vertex& b);
private:
    char data;
    Edge * firstIn, *firstOut;

public:
    Vertex(char Data, Edge * First_In = nullptr, Edge * First_Out = nullptr);
    Vertex();
    ~Vertex();
};
// Support function 'std::find' work.
inline bool operator==(const Vertex& a, const Vertex& b){ return a.data == b.data; }

Vertex ::Vertex(char Data, Edge * First_In, Edge * First_Out)
:data(Data), firstIn(First_In), firstOut(First_Out)
{}

Vertex ::Vertex()
:data(), firstIn(nullptr), firstOut(nullptr){}

Vertex ::~Vertex()
{}
#endif