#include "HuffmanTree.h"
#include <iostream>
using namespace std;

int main(){
    ifstream text("D:\\pspro\\C_C++_pro\\DataStructure_Algorithms\\HuffmanTree\\rsrc\\Test.txt");
    // ifstream text("D:\\pspro\\C_C++_pro\\DataStructure_Algorithms\\HuffmanTree\\rsrc\\hamlet.txt", std::ios::in);
    HuffmanTree ht(text);
    ht.test();
    // ht.getCodingTable();

    return 0;
}