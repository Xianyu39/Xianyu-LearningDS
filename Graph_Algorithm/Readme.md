# Introduction
This is a simple project to illustrate some basic graph algorithms. The `Main.cpp` is just a demo. To get the shared library, please use **CMake** build the the library in your device to make sure that it could work successfully.

The library PATH is:
```powershell
build\bin\
```

If you want to build by yourself, please leave at least 1 .cpp file even it is empty.

# UGraph
`class UGraph` is a class template, which allows you contain any type of data. You can also inherit it as a base class and create your own graph class.
"UGraph" its name means "Universal Graph", using **Adjacency Matrix** represent the edges. It allows you define your own rules about what the value in the matrix represents. In default, 0 means no edge between this 2 vertecies; non-zero value means the edges weight.
## Initial
As the vertecies type is unknown, you should create an array contains the vertecies data and a `ifstream` object provides the edges data to initial the graph. Obviewsly, you also can provide no arguments create an empty graph.

The edge data should be wrote in this format:
```txt
0 1 1
0 1 2
0 2 3
2 1 3

1 2 1
4 1 1
```
Each line indicates an edge. The first and last number is the index of vertex that connect with the tail and head; the middle one is the weight. You can insert newline anywhere you want to make your input data more clearly.

If you wanna create a undirected graph and think that using a pair of directed edges is too stupid, you could change the paramiter `Mode`.

```cpp
UGraph::Mode::DIRECTED,
UGraph::Mode::UN_DIRECTED
```
In default, the `Mode` is `UN_DIRECTED`.

## Algorithms
The graph algorithms were written as member functions of `class UGraph`. So all of them were based on adjacency matrix. But you can easily write your own algorithms base on the graph that in other forms... I think so...
> I assume that you won't try things like pointer linked graph...

Algorithms, including: 

- Traverse : BFS & DFS
- Minimum spanning tree : Prim & Kruskal
- Shortest path : Dijistra & Floyd-Warshall
- Topological sort

All of these algorithms are the BASIC implement, which have not been optimized. I can't assert that they have no coverd bugs or can work in any circustance smoothly.