// @ shit mountain
#include <iostream>
#include <vector>
using namespace std;

struct Alias{
    // Contains all the alias will be used.
    using size_t = unsigned int;
};

class Node: public Alias {
    // Linked list node, but use an index substitute pointer.
public:
    int data;
    size_t next;

    Node() : data(), next(0) { }
    Node(int data, size_t next) : data(data), next(next) { }
};

class Static_List: public Alias {
private:
    vector<Node> vec;
    size_t Max_Size = 100;
    size_t tail; // tail means the place BEFORE the last;

public:
    Static_List();
    bool insert(int data, size_t ix);
    void push_back(int data);
    void push_front(int data) { insert(data, 0); }
    void erase(size_t ix);
    void pop_back();
    void pop_front() { erase(0); }
    void test(){
        size_t i{vec.back().next};
        while(i){
            cout << vec[i].data << '\t';
            i = vec[i].next;
        }
    }
};

Static_List::Static_List() : tail{Max_Size - 1}{
    vec.reserve(Max_Size);
    // link the element one by one
    for (size_t i = 0; i < Max_Size; i++)
        vec.push_back(Node(0, i + 1));

    // Set null
    vec.back().next = 0;
}

bool inline 
Static_List::insert(int data, size_t ix) {
    size_t pos{Max_Size - 1};

    // find the place
    for (size_t i = 0; i < ix && pos; i++) {
        pos = vec[pos].next;
    }
    if(!pos)
        return false;

    // Insert
    size_t newSpace{vec.front().next};
    vec.front().next = vec[vec.front().next].next;
    vec[newSpace].data = data;
    auto tmp = vec[pos].next;
    vec[pos].next = newSpace;
    vec[newSpace].next = tmp;

    return true;
}
void inline 
Static_List::pop_back(){
    // Initialization
    auto tail{Max_Size - 1};
    while(vec[vec[tail].next].next){
        tail = vec[tail].next;
    }

    // erase
    auto backup{vec.front().next};// Backup list
    auto tmp{vec[vec[tail].next].next};// List after erase tailition

    vec[vec[tail].next].next = backup;
    vec.front().next = vec[tail].next;
    vec[tail].next = tmp;
}

void inline 
Static_List::push_back(int data){
    // Initialization
    if(tail == Max_Size - 1){
        while(vec[tail].next){
            tail = vec[tail].next;
        }
    }
    // Insert
    size_t newSpace{vec.front().next};
    vec.front().next = vec[vec.front().next].next;
    vec[newSpace].data = data;
    auto tmp = vec[tail].next;
    vec[tail].next = newSpace;
    vec[newSpace].next = tmp;

    tail = vec[tail].next;
}

void inline
Static_List::erase(size_t ix){
    size_t pos{Max_Size - 1};

    // find the place
    for (size_t i = 0; i < ix && vec[vec[pos].next].next; i++) {
        pos = vec[pos].next;
    }
    
    // erase
    auto backup{vec.front().next};// Backup list
    auto tmp{vec[vec[pos].next].next};// List after erase position

    vec[vec[pos].next].next = backup;
    vec.front().next = vec[pos].next;
    vec[pos].next = tmp;
}

int main() {
    Static_List ls;
    ls.push_front(10);
    ls.push_back(11);
    ls.push_front(12);
    ls.push_back(13);
    ls.push_front(14);
    ls.pop_back();
    ls.push_back(15);
    ls.push_front(16);

    // ls.erase(0);

    // ls.insert(100, 3);
    ls.push_back(250);
    // ls.erase(8);
    ls.pop_back();
    ls.pop_back();
    // ls.pop_front();
    // ls.pop_front();

    ls.test();

    return 0;
}