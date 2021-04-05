#include "Node.h"

inline bool operator<(const Node &a, const Node &b){
    return a.weight < b.weight;
}