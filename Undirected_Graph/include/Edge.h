#ifndef __EDGE_H__
#define __EDGE_H__
class Edge
{
    using size_t = unsigned;
public:
    size_t ivex, jvex;// 2 vertecis
    Edge* inext, *jnext;
    size_t weight;

    Edge(size_t vex1, size_t vex2, size_t weight = 1, Edge* Inext = nullptr, Edge* Jnext = nullptr);
    ~Edge(){}
};

#endif