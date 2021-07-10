#include <iostream>
#include<fstream>
#include "include/RBTree.hpp"
using namespace std;

int main() {
    RBTree<int> rb;
    rb.insert(41);
    rb.insert(38);
    rb.insert(31);
    rb.insert(12);
    rb.insert(19);
    rb.insert(8);
    rb.insert(6);
    rb.insert(7);
    rb.insert(9);
    rb.insert(3);

    rb.test();

    // cout << "Hello World" << endl;
    return 0;
}