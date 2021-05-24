/*******************************************************************************************************
 * Double linked list library
 * Copyright (C) 2021 XianYu 3136867070@qq.com
 *
 * This file includes the whole parts of the double linked list.
 *
 * This is a student work, which is not fully complete. The iterator class have not been done yet, and the
 * member function 'sort' of the class template 'List' is also uncomplete. Don't mind that, I believe
 * there are no project would need such a library, the std::list is a better choice.
 * @file List.hpp
 * @brief Including all of the library, no .dll etc files are necessary.
 *
 * details.
 * @author XianYu
 * @version 1.0.0
 *
 *------------------------------------------------------------------------------------------------------
 * Change history:
 * <Date>    | <Version> | <Author> | Description
 *------------------------------------------------------------------------------------------------------
 * 2021.5.22 | 1.0.0     | XianYu   | The first edition 
 * *****************************************************************************************************/

#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <iostream>

/**
 * @brief The namespace of class List and Node.
 * The namespace 'MyList' includes the List and Node class,
 * also includes an alia called 'num', which is used to count.
*/
namespace MyList
{
    template<typename Tp>
    class List;
    template<typename Tp>
    class Node;

    /**
     * @brief num is uses to count, just like 'size_t', but it allows negative number.
    */
    using num = long;

}; // namespace MyList

using MyList::List;
using MyList::Node;
using std::cout;
using std::endl;

/**
 *@brief The basic element of the list.
 *This class only includes pointers to the object, so which uses small pieces memory.
 *At the same time, you shall watch out the dtor in any time.
 *Moreover, this class can be operated by list object only, all of its members are private.
 *@param Tp The element type of the node.
*/
template<typename Tp>
class MyList::Node {
    friend class MyList::List<Tp>;
    Tp* Object;// The data of the node.
    Node* prev, * next;// To previous and next node.
    /**
     * @brief Ctor, also is the default ctor, which builds the Node<Tp> object.
     * @param obj Pointer to the data object, please ensure that the data in heap.
     * @param previews Pointer to previous node.
     * @param next Pointer to next node.
    */
    Node(Tp* obj = nullptr, Node* previews = nullptr, Node* next = nullptr) :
        Object(obj), prev(previews), next(next) {}
    ~Node() {
        if (Object) { delete Object; }
    }
};

/**
 * @brief The class template 'List', which is a double linked list.
 * A List object has its own allocator and can be sorted by method 'sort'. 
 * Undoubtfully, the basic functions are also be included.
 * The list is like a circle, begin and ended at the same node called 'NIL'.
 *
 * @param Tp data type of the list contained.
*/
template<typename Tp>
class MyList::List {
    friend class MyList::Node<Tp>;

private:
    Node<Tp>* NIL;// The begin and also the end of the list.
    Node<Tp>* pool;// The begin and also the end of the memory pool.
    num length; // Element number of the linked list
    num pool_length; // free node number of the memory pool.

    /**
     * @brief Add a piece of memory that the pointer points to into the pool.
     * In most of times, it is used to store the discarded nodes, and the nodes are required be in heap.
     * @param nd The node that need to add to pool. Make sure it points to heap memory.
     * @return Return a pointer points to the new one that added to pool.
    */
    Node<Tp>* addToPool(Node<Tp>* nd) {
        nd->next = pool->next; 
        pool->next->prev = nd;
        nd->prev = pool;
        pool->next = nd;
        ++pool_length;

        return nd;
    }

    /**
     * @brief Ask the pool to get a node of memory.
     * @return Return a pointer that points to that allocated memory. If the pool is empty, return nullptr.
    */
    Node<Tp>* allocateMemory() {
        if (pool->next == pool) { return nullptr; }
        Node<Tp>* nd{ pool->next };
        pool->next = nd->next;
        nd->next->prev = pool;
        nd->prev = nd->next = nullptr;

        --pool_length;
        return nd;
    }

    /**
     * @brief Exchange the 2 pointers' values. This function is use to simplify the codes.
     * @param a First pointer that point to the data objcet.
     * @param b Second pointer that point to the data objcet.
    */
    void swap(Tp*& a, Tp*& b) {
        auto tmp{ a };
        a = b;
        b = tmp;
    }

public:
    /**
     * @brief Default ctor, build an empty list.
    */
    List()
        :length(0),
        pool_length(0),
        NIL(new Node<Tp>(nullptr, nullptr, nullptr)),
        pool(new Node<Tp>(nullptr, nullptr, nullptr))
    {
        NIL->next = NIL->prev = NIL;
        pool->next = pool->prev = pool;
    }
    ~List();
    /**
     * @brief Get the number of objects the list contains.
     * @return Return a 'num' that indicates the number of objects list contains.
    */
    num size()const { return length; }
    bool isEmplty()const { return bool(length); }
    Node<Tp>* front() { return NIL->next; }
    Node<Tp>* back() { return NIL->prev; }
    const Node<Tp>* front()const { return NIL->next; }
    const Node<Tp>* back()const { return NIL->prev; }
    Node<Tp>* insert(Node<Tp>* it, const Tp& val);// Insert the value in the place AFTER it.
    Node<Tp>* push_back(const Tp& val) { return insert(back(), val); }
    Node<Tp>* push_front(const Tp& val) { return insert(NIL, val); }
    Tp pop_back() { return erase(back()); }
    Tp pop_front() { return erase(front()); }
    Tp erase(Node<Tp>* it);
    void sort(Node<Tp>* begin, Node<Tp>* end);
    void sort() { sort(front(), NIL); }
    Node<Tp>* search(const Tp& key)const;

    void test() const {
        cout << "List: ";
        for (Node<Tp>* p{ NIL->next };p != NIL;p = p->next)
            cout << *(p->Object) << " ";
        cout << endl << "Pool: ";
        for (Node<Tp>* p{ pool->next };p != pool;p = p->next)
            cout << *(p->Object) << " ";
        cout << endl;
    }
};

template<typename Tp>
Node<Tp>* List<Tp>::insert(Node<Tp>* it, const Tp& val) {
    Node<Tp>* tmp{ it->next };
    if (it->next = allocateMemory(), !it->next) {
        it->next = new Node<Tp>(new Tp(val), it, tmp);    
    }
    else {
        if (it->next->Object)
            *it->next->Object = val;
        else
            it->next->Object = new Tp(val);
        
        it->next->prev = it;
        it->next->next = tmp;
    }
    tmp->prev = it->next;

    ++length;
    return it->next;
}

template<typename Tp>
Tp List<Tp>::erase(Node<Tp>* it) {
    it->prev->next = it->next;
    it->next->prev = it->prev;
    Tp tmp{ *it->Object };
    addToPool(it);

    --length;
    return tmp;
}

template<typename Tp>
void List<Tp>::sort(Node<Tp>* begin, Node<Tp>* end) {
    if (begin != end->prev && begin != end) {
        Node<Tp>* l{ begin->prev }, * r{ begin }, * flag{ end->prev };
        // Partition
        while (r != flag) {
            if (*r->Object < *flag->Object) {
                l = l->next;
                swap(r->Object, l->Object);
            }
            r = r->next;
        }
        l = l->next;
        swap(l->Object, flag->Object);

        this->sort(begin, l);
        this->sort(l->next, end);
    }
}

template<typename Tp>
Node<Tp>* List<Tp>::search(const Tp& key)const {
    if (isEmplty()) { return nullptr; }
    for (Node<Tp>* p{ NIL->next }; p != NIL; p = p->next) {
        if (*p->Object == key) {
            return p;
        }
    }
    return nullptr;
}

template<typename Tp>
List<Tp>::~List() {
    switch (size())
    {
    case 0:
        break;
    case 1:
        delete front();
        break;
    default:
        Node<Tp>* ptr{ NIL->next->next };
        while (ptr != NIL) {
            delete ptr->prev;
            ptr = ptr->next;
        }
        delete ptr->prev;
        break;
    }
    switch (pool_length)
    {
    case 0:
        break;
    case 1:
        delete pool->next;
        break;
    default:
        Node<Tp>* ptr{ pool->next->next };
        while (ptr != pool) {
            delete ptr->prev;
            ptr = ptr->next;
        }
        delete ptr->prev;
        break;
    }

    delete pool;
    delete NIL;
}

#endif // !__LIST_HPP__