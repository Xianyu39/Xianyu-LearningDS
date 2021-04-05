#include "HuffmanTree.h"
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

HuffmanTree::HuffmanTree(const string& str)
{
    // Store the characters and their number.
    map<char, size_t> dict;
    for (size_t i{0}; i < str.size(); ++i){
        dict[str[i]]++;
    }

    // Store the data in a list
    list<Node*> ls;
    for(auto& i : dict){
        // std::cout << i.first << ' ' << i.second << ' ' << (i.second * 1000) / Total_words << std::endl;
        ls.push_back(new Node(i.first, i.second));
    }

    // Construct a Huffman Tree.
    Buid_HuffmanTree(ls);
}

HuffmanTree::HuffmanTree(ifstream &ifs){
    char s[100];
    string str;
    while (ifs.read(s, 100)){
        str = str + s;
    }

    // Count the characters and their amount.
    map<char, size_t> dict;
    size_t Total_words{str.size()};

    for (size_t i{0}; i < Total_words; ++i){
        dict[str[i]]++;
    }

    // Store the data in a list
    list<Node*> ls;
    for(auto& i : dict){
        // std::cout << i.first << ' ' << i.second << ' ' << (i.second * 1000) / Total_words << std::endl;
        ls.push_back(new Node(i.first, i.second));
    }

    // Construct a Huffman Tree.
    Buid_HuffmanTree(ls);
    // cout << ls.front()->weight << ' ' << Total_words;
    code(root);
}

void HuffmanTree::Buid_HuffmanTree(list<Node*>& ls){
    while (ls.size() > 1) {
        // sort by weight
        ls.sort([](Node *a, Node *b) -> bool {
            return a->weight < b->weight;
        });

        // Build tree
        Ptr first{ls.begin()}, second{++first};
        first = ls.begin();

        auto weight{(*first)->weight + (*second)->weight};
        root = new Node('#', weight);
        root->Lchild = *first;
        root->Rchild = *second;

        ls.erase(first);
        ls.erase(second);
        ls.push_front(root);
    }

    root = ls.front();
}
HuffmanTree::~HuffmanTree()
{
    Destroy(root);
}

inline void HuffmanTree::Destroy(Node* root){
    if(root){
        if(root->Lchild){
            Destroy(root->Lchild);
        }
        if(root->Rchild){
            Destroy(root->Lchild);
        }
        // cout << "Delete " << root->ch << endl;
        delete root;
    }
}

void HuffmanTree::test(){
    cout << "Pre:" << endl;
    Pre_order_traverse(root);
    cout << endl
         << "Mid:" << endl;
    Mid_order_traverse(root);
}
void HuffmanTree::Pre_order_traverse(Node *root){
    if(root){
        // if(root->ch!='#'){
            cout << root->ch << ' ';
            cout<< root->weight << endl;
        // }
        Pre_order_traverse(root->Lchild);
        Pre_order_traverse(root->Rchild);
    }
}

void HuffmanTree::Mid_order_traverse(Node *root){
    if(root){
        Mid_order_traverse(root->Lchild);
        // if(root->ch!='#'){
            cout << root->ch << ' ';
            cout << root->weight << endl;
        // }
        Mid_order_traverse(root->Rchild);
    }
}

void HuffmanTree::code(Node *root){
    if(root){
        if(root->Lchild){
            root->Lchild->weight = 0;
            code(root->Lchild);
        }
        if(root->Rchild){
            root->Rchild->weight = 1;
            code(root->Rchild);
        }
    }
}

void HuffmanTree::_getCodingTable(Node* root, ostream &os){
    if(root){
        if(root->ch == '#'){
            os << root->weight;
        }else{
            os << "\t\t" << root->ch << endl;
        }
        _getCodingTable(root->Lchild, os);
        _getCodingTable(root->Rchild, os);
    }
}

void HuffmanTree::getCodingTable(ostream &os){
    _getCodingTable(root, os);
}