#include <iostream>
using namespace std;

// Basic component of linked list;
class Node{
public:
    int data;
    Node *next;

    Node():data(), next(nullptr){}
    Node(int Data, Node* Next): data(Data), next(Next) {}
};

class Linked_Queue {
private:
    // Point to list head
    Node *rear;
    // Point to list tail
    Node *front;
    size_t length;

public:
    Linked_Queue(): rear(nullptr), front(nullptr), length(0) {
        rear = new Node(int(), nullptr);
        front = rear;
    }
    ~Linked_Queue(){
        if(length == 0){
            delete rear;
            rear = nullptr;
        }else{
            for (auto ptr{rear->next}; ptr; rear = ptr, ptr = ptr->next){
                delete rear;
            }
            delete rear;
            rear = nullptr;
        }
    }

    void push(int val){
        front->next = new Node(val, nullptr);
        front = front->next;
        ++length;
    }

    void pop(){
        auto tmp{rear};
        rear = rear->next;
        delete tmp;
        --length;
    }

    bool isEmpty() const { return !length; }
    size_t size() const { return length; }

    void test()const{
        for (auto ix{rear->next}; ix; ix = ix->next) {
            cout << ix->data << ' ';
        }
        cout << endl
             << "Length: " << length << endl;
    }
};

int main(){
    Linked_Queue ls;
    ls.push(1);
    ls.push(2);
    ls.push(3);
    ls.push(4);
    ls.push(5);

    ls.pop();
    ls.pop();
    ls.pop();
    ls.test();

    return 0;
}