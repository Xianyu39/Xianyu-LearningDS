/**
 * Red-Black Tree.
 * This is an illustration of RB Tree data structure. You won't know how much I paid in such thing.
 * Date: 2021.7.1
 * Author: Xianyu
*/
#ifndef __RBTREE_HPP__
#define __RBTREE_HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

// Pre-declaration of RBTree.
template<class Tp>
class RBTree;

// Contains the information about red node style, which is used to visualizing.
const string redNodeMessage("bgcolor=red fontcolor=white,");

// Contains the information about black node style, which is used to visualizing.
const string blackNodeMessage("bgcolor=black fontcolor=white,");

// NIL node style, add a name before it to generate a NIL node.
const string nilMessage("[bgcolor=black, shape=box, fontcolor=white, width=0.4, height=0.2,label=\"NIL\"]");

/**
 *@brief Generating a set of unique numbers to distinguish nodes.
*/
inline size_t getID() {
    static size_t i = 0;
    return i++;
}

/**
 *@brief The colors of nodes, include red and black.
*/
enum RB { RED, BLACK };

/**
 * @brief Node is the basic element of RBTree.
*/
template<class Tp>
class Node {
private:
    friend class RBTree<Tp>;

    RB color;
    Tp key;
    Node* left, * right, * parent;
    size_t num = 1;

    // visualizer
    string id;

    /**
     *@brief Generating full visual nodes declartion.(The content in [])
    */
    string toString() {
        stringstream ss;
        ss << id;
        if (color == RED) {
            ss << "[" << redNodeMessage << "label=\"" << key << "\"]";
        }
        else {
            ss << "[" << blackNodeMessage << "label=\"" << key << "\"]";
        }
        return ss.str();
    }

    /**
     *@brief Default color is red, and its pointers were pointed to null.
    */
    Node() : color(RED), key(), left(nullptr), right(nullptr), parent(nullptr), id() {
        stringstream ss;
        // ss << "n" << getID();
        ss << "n" << key;
        id = ss.str();
    }
    /**
     *@brief Default color is red, and its pointers were pointed to null.
     *@param key: Key value of the node.
    */
    Node(const Tp& key) :key(key), color(RED), left(nullptr), id() {
        stringstream ss;
        // ss << "n" << getID();
        ss << "n" << key;
        id = ss.str();
    }
    /**
     *@brief Default color is red, and its pointers were pointed to null.
     *@param key: Key value of the node.
    */
    Node(Tp&& key) :key(key), color(RED), left(nullptr), id() {
        stringstream ss;
        // ss << "n" << getID();
        ss << "n" << key;
        id = ss.str();
    }
};

/**
 *@brief This is the demo of RB tree.
 *@param Tp: The key type of the tree, which is required to be comparable. (Surpport the '>' and '<' operators.)
*/
template<class Tp>
class RBTree {
private:
    // Nil is the public leaf of the RBTree.
    Node<Tp> nil;
    // Root
    Node<Tp>* root;

    /**
     *@brief Traversing the whole RBTree and generating the main part of visualizing script.
     *@param root: Traversing will begin here.
     *@param os: dot code will be outputed to os, it is usually a *.dot file.
    */
    void visualize_walk(Node<Tp>* root, std::ostream& os) {
        // Just like getID().(I don't know why I didn't use it directly.)
        static int nil_code = 0;

        // Generating root node and connecting it and its parent if it has.
        if (root == this->root) {
            os << root->toString() << endl;
        }
        else {
            os << root->toString() << endl;
            os << root->parent->id << "->" << root->id << endl;
        }

        // Visualizing 2 subtrees if root and using NIL as leaves.
        if (root->left != &nil) { visualize_walk(root->left, os); }
        else {
            os << "nil" << nil_code << nilMessage << endl;
            os << root->id << "->" << "nil" << nil_code << nilMessage << endl;
            ++nil_code;
        }
        if (root->right != &nil) { visualize_walk(root->right, os); }
        else {
            os << "nil" << nil_code << nilMessage << endl;
            os << root->id << "->" << "nil" << nil_code << nilMessage << endl;
            ++nil_code;
        }
    }

    void LeftRotate(Node<Tp>* x) {
        Node<Tp>* y = x->right;
        x->right = y->left;
        y->left->parent = x;
        y->parent = x->parent;

        if (x == root) { root = y; }
        else if (x == x->parent->left) { x->parent->left = y; }
        else { x->parent->right = y; }

        x->parent = y;
        y->left = x;
    }
    void RightRotate(Node<Tp>* y) {
        Node<Tp>* x = y->left;
        x->parent = y->parent;
        y->left = x->right;
        x->right->parent = y;

        if (y == root) { root = x; }
        else if (y == y->parent->left) { y->parent->left = x; }
        else { y->parent->right = x; }

        y->parent = x;
        x->right = y;
    }

    /**
     *@brief Keeping RB nature of the RBTree after insertion.
     *@param nNode: Pointer to new-inserted node.
    */
    void InsertFixup(Node<Tp>* nNode) {
        while (nNode->parent->color == RED) {
            if (nNode->parent == nNode->parent->parent->left) {
                Node<Tp>* uncle = nNode->parent->parent->right;
                if (uncle->color == RED) {
                    // Case 1
                    nNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    nNode->parent->parent->color = RED;
                    nNode = nNode->parent->parent;
                }
                else {
                    if (nNode == nNode->parent->right) {
                        // Case 2
                        nNode = nNode->parent;
                        LeftRotate(nNode);
                    }
                    // Case 3
                    nNode->parent->color = BLACK;
                    nNode->parent->parent->color = RED;
                    RightRotate(nNode->parent->parent);
                }
            }
            else {
                Node<Tp>* uncle = nNode->parent->parent->left;
                if (uncle->color == RED) {
                    // Case 1
                    nNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    nNode->parent->parent->color = RED;
                    nNode = nNode->parent->parent;
                }
                else {
                    if (nNode == nNode->parent->left) {
                        // Case 2
                        nNode = nNode->parent;
                        RightRotate(nNode);
                    }
                    // Case 3
                    nNode->parent->color = BLACK;
                    nNode->parent->parent->color = RED;
                    LeftRotate(nNode->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

public:
    RBTree() :nil(), root(new Node<Tp>()) {
        nil.color = RB::BLACK;
        root->color = RB::BLACK;
        root->left = &nil;
        root->right = &nil;
        root->num = 0;
        root->parent = &nil;
    }

    ~RBTree() { destruct(root); }

    void destruct(Node<Tp>* root) {
        if (root != &nil) {
            destruct(root->left);
            destruct(root->right);
            // cout << "Destruct " << root->key << endl;
            delete root;
        }
    }

    void insert(const Tp& key) {
        // If tree is empty
        if (root->num == 0) {
            root->key = key;
            root->num = 1;
        }
        else {
            // Find a suitable place for new key
            Node<Tp>* ptr = root;
            Node<Tp>* parent = nullptr;
            while (ptr != &nil) {
                parent = ptr;
                if (ptr->key < key) { ptr = ptr->right; }
                else if (ptr->key > key) { ptr = ptr->left; }
                else {
                    cout << "The value " << key << " has been inserted to the tree." << endl;
                    return;
                }
            }
            // Insert, and keep RB nature through InsertFixup().
            if (parent->key < key) {
                parent->right = new Node<Tp>(key);
                parent->right->parent = parent;
                parent->right->left = parent->right->right = &nil;

                InsertFixup(parent->right);
            }
            else {
                parent->left = new Node<Tp>(key);
                parent->left->parent = parent;
                parent->left->left = parent->left->right = &nil;

                InsertFixup(parent->left);
            }
        }
    }

    void test() {
        // Visualizing script.
        std::ofstream os;
        // LeftRotate(root->right);
        os.open("D:/pspro/C_C++_pro/DataStructure_Algorithms/Xianyu-LearningDS/RBTree/Test.dot", std::ios::trunc);
        visualize(os);
    }

    /**
     *@brief Generating dot code to visualize the RBTree. 'os' usually is the dot script.
     *@param os: dot script, usually is an opened *.dot file.
    */
    void visualize(std::ostream& os) {
        if (!os) {
            throw "Open visualizing script file failed.";
            std::cerr << "Open visualizing script file failed.";
        }
        os << "digraph{\n";
        os << "label=\"Red-black Tree\"" << endl;
        visualize_walk(root, os);
        os << "}";

        cout << "Visualized successfully." << endl;
    }
};

#endif