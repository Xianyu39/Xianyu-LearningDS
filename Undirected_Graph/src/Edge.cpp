#include "Edge.h"

Edge::Edge(size_t vex1, size_t vex2,
            size_t weight, 
            Edge* Inext, Edge* Jnext)
            : ivex(vex1), jvex(vex2), weight(weight), inext(Inext), jnext(Jnext) {}
