#ifndef __GRAPH_H__
#define __GRAPH_H__
#include "Edge.h"
#include "Vertex.h"
#include "Alias.h"
#include <vector>
#include <iostream>
#include <string>

const std::string Path{"./../../rsrc/"};

// Using Orthogonal list
class Graph : public Alias
{
    friend class Vertex;
    friend class Edge;
private:
    std::vector<Vertex> vertexList;

public:
    Graph(std::istream& input);
    ~Graph();
};
#endif