#include <iostream>
#include <vector>
using namespace std;

class Child{
public:
    int child;
    Child *next;

    Child(int ix, Child *next = nullptr) : child(ix), next(next) { }
};

class Node{
public:
    char Data;
    Child* ch;

    Node(char data) : Data(data), ch(nullptr) { }
};

// Using list contain the child' index, vector stores the data.
class Tree{
private:
    vector<Node> vec;

public:
    Tree() : vec() { }
    bool isEmpty() const { return vec.empty(); }
    // void addChild()
};

int main(){

}