#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <iostream>
#include <string>

template<class T>
class Tree;

template<class T>
class Node {
private:
    friend class Tree<T>;

    T* value;
    Node<T>* leftChild, * rightChild;

    Node(T* val = nullptr, Node<T>* lchild = nullptr, Node<T>* rchild = nullptr)
        :value(val), leftChild(lchild), rightChild(rchild) {}
};

template<class T>
class Tree
{
private:
    Node<T>* root;
    
public:
    Tree() {
        
    }
    ~Tree() {}
};

#endif