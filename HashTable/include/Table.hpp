#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <iostream>
#include "Hash.hpp"

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
    Num _tableSize;
    Hash<Key> hash;


public:
    HashTable() {}

};

#endif