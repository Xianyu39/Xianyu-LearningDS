#ifndef __HASH_HPP__
#define __HASH_HPP__

#include <iostream>
#include "Table.hpp"
#include <string>

using std::cout;
using std::endl;
using Num = unsigned long;

/**
 * @brief Hash functor, you can inherit this class and
 * rewrite the virtual operator() to use your own hash function.
 * @param Key key type.
*/
template<typename Key>
class Hash {
public:
    virtual Num operator()(const Key& key, Num tableSize) {
        return key % tableSize;
    }

    Hash() {}
};

#endif