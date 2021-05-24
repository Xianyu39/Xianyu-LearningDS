#ifndef __HASH_HPP__
#define __HASH_HPP__

#include <iostream>
#include <Table.hpp>

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
    template<typename T>
    friend class HashTable<Key, T>;
    virtual Num operator()(const Key& key) {
        return 1;
    }

    Hash(){}
};

#endif