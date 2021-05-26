#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <iostream>
// #include "Table.hpp"

using std::cout;
using std::endl;
using Num = unsigned long;

template<typename Key, typename Value>
class HashTable;

template<typename Key, typename Value>
class HashNode {
    friend class HashTable<Key, Value>;

private:
    Key* key;
    Value* val;
    HashNode* next;

    HashNode(Key* key = nullptr,
        Value* val = nullptr,
        HashNode* next = nullptr)
        :key(key), val(val), next(next) {}
};

template<typename Key, typename Value>
class List {
private:
    friend class

    void push();
};

#endif