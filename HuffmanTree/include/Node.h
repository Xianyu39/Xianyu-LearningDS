#ifndef NODE_H_
#define NODE_H_

class HuffmanTree;
// Basic element of Huffman Tree, contains character, weight, child, and some operators.
class Node {
    // public:
    using size_t = unsigned int;
    friend class HuffmanTree;

    char ch;
    size_t weight;
    Node *Lchild;
    Node *Rchild;

    Node(char Character, size_t Weight, Node *Lchild = nullptr, Node *Rchild = nullptr)
        : ch(Character), weight(Weight), Lchild(Lchild), Rchild(Rchild) { }

    // Only compare the weight.
    friend bool operator<(const Node &a, const Node &b);
    // Only compare the weight.
    friend bool operator>(const Node &a, const Node &b) { return !(a < b); }
    // Only compare the weight.
    friend bool operator==(const Node &a, const Node &b) { return !(a < b) && !(a > b); }

    // Only copy the ch and weight
    Node operator=(const Node& rhs){
        this->ch = rhs.ch;
        this->weight = rhs.weight;
        return *this;
    }
};

#endif