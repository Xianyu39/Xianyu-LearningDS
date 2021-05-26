#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <iostream>
#include "Hash.hpp"
#include "List.hpp"

using std::cout;
using std::endl;
using Num = unsigned long;

/**
 * @brief Hashtable, using chaining method to deal with collision.
 * @param Key key type ,you can search the values fastly by key.
 * @param Value Data type.
*/
template<typename Key, typename Value>
class HashTable {
private:
    Num tableSize;
    Hash<Key> hash;

public:
    HashTable(Hash<Key>& hash, Num size = 10) :tableSize(size), hash(hash) {}
    HashTable(Num size = 10) :tableSize(size), hash() { cout << "Done" << endl; }

};

#endif