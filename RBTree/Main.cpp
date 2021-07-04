#include <iostream>
#include<fstream>
#include "include/RBTree.hpp"
using namespace std;

int main() {
    RBTree<int> rb;
    rb.insert(0);
    rb.insert(11);
    rb.insert(4);
    rb.insert(8);
    rb.insert(1);
    rb.insert(2);
    rb.insert(6);
    rb.insert(7);
    // rb.insert(9);
    // rb.insert(3);
    rb.test();

    // cout << "Hello World" << endl;
    return 0;
}