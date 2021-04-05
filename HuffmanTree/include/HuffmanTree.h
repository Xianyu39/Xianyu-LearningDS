#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_
#include "Node.h"
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include <iostream>
using namespace std;

class HuffmanTree
{
private:
    Node *root;

public:
    using Ptr = list<Node *>::iterator;

    HuffmanTree() : root(nullptr) { }
    HuffmanTree(ifstream &ifs);
    HuffmanTree(const string& str);
    // Using a list to build a tree
    void Buid_HuffmanTree(list<Node*>& ls);
    // Release the used memory
    void Destroy(Node* root);
    void code(Node *root);
    ~HuffmanTree();
    void getCodingTable(ostream &os = cout);
    void _getCodingTable(Node* root, ostream &os = cout);

    void test();
    void Pre_order_traverse(Node *root);
    void Mid_order_traverse(Node *root);
};

#endif