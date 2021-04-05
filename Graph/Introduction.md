# Introduction
This project contains a shared library(`libGraph.dll`) of Graph and related algorithms. The `Main.exe` is a demo.

# Graph
Default is **Direcrted  Network**. Contains both directions and weights. You can set the weight to a constant number and connect 2 vertex with 2 contary direction edge to simplify it.

## Initial
Graph contains too much information and is hard to initial by typing on keyboard. So please create a `Initial.txt` file in this
form:

```txt
A B C D E F *
A 12 E
A 1 B
C 1 A
E 2 F
```
1, First line is the vertecis data, using a '*' character as end label.

2, Following are the edges. Each line indicates an edge, left to right are tail vertex, weight, head vertex.