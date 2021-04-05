/*
A linked list, no surprise.
*/

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

class Loop_list{
    using size_t = unsigned long long;

private:
    // 'rear' points to the LAST element of the list;
    Node *rear;
    Node *head;
    size_t size;

    // Prior means place before the target.
    void insert_val(Node *prior, int val);
    // Prior means place before the target.
    void remove_val(Node* prior){
        auto target{prior->next}, successor{target->next};
        prior->next = successor;
        delete target;
        --size;
    }

public:
    Loop_list(): rear(nullptr), head(nullptr), size(0) {
        rear = new Node();
        rear->next = new Node(int(), rear);
        head = rear->next;
    }
    ~Loop_list(){
        auto const* end{rear};
        for (; rear != end; rear = head, head=head->next){
            delete rear;
        }
    }
    bool isEmpty() const { return !size; }
    size_t length() const { return size; }
    void push_back(int val) { 
        switch (size)
        {
        case 0:
            head->data = val;
            ++size;
            break;
        case 1:
            rear->data = val;
            ++size;
            break;
        default:
            insert_val(rear, val);
            rear = rear->next;
            break;
        }
    }
    void push_front(int val){
        switch (size)
        {
        case 0:
            head->data = val;
            ++size;
            break;
        case 1:
            rear->data = val;
            swap(*rear, *head);
            ++size;
            break;
        default:
            insert_val(rear, val);
            head = rear->next;
            break;
        }
    }

    void insert(Node* where, int val){
        if(where == head){
            push_front(val);
        }else if(where == rear){
            push_back(val);
        }else {
            auto prior{rear};
            while (prior->next != where)
                prior = prior->next;
            insert_val(prior, val);
        } 
    }
    // If not found, return nullptr;
    Node* find(int val) const{
        auto ptr{head->next};
        if(head->data == val){
            return head;
        }
        while(ptr->data != val && ptr != head)
            ptr = ptr->next;
        if(ptr == head){
            return nullptr;
        }else{
            return ptr;
        }
    }

    void pop_back(){
        switch (size)
        {
        case 0:
            break;
        case 1:
            --size;
            break;
        case 2:
            --size;
            break;
        // Elements are more than 2
        default:
            static Node *beforeRear{head};
            while(beforeRear->next != rear)
                beforeRear = beforeRear->next;
            remove_val(beforeRear);
            rear = beforeRear;
            break;
        }
    }

    void pop_front(){
        switch (size)
        {
        case 0:
            break;
        case 1:
            --size;
            break;
        case 2:
            head->data = rear->data;
            --size;
            break;
        
        default:
            remove_val(rear);
            head = rear->next;
            break;
        }
    }

    void remove(Node *target){
        if(!size){
            return;
        }

        if(target == head){
            pop_front();
        }else if(target == rear){
            pop_back();
        }else{
            auto prior{head};
            while(prior->next != target)
                prior = prior->next;

            remove_val(prior);
        }
    }

    void test(){
        for (auto i{head}; i != rear; i = i->next){
            cout << i->data << "   ";
        }
        cout << rear->data << endl;

        cout << "head->data: " << head->data << endl;
        cout << "rear->data: " << rear->data << endl;
        cout << "Size: " << size << endl;
    }
};

inline void Loop_list::insert_val(Node *prior, int val){
    auto tmp{prior->next};
    prior->next = new Node(val, tmp);
    ++size;
}

int main(){
    Loop_list ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(5);
    ls.push_front(6);
    ls.push_front(7);
    ls.push_front(8);
    ls.push_front(9);
    ls.push_front(10);
    ls.insert(ls.find(7), 70);
    ls.test();

    ls.pop_back();
    ls.pop_back();
    ls.pop_back();
    ls.test();

    ls.pop_front();
    ls.pop_front();
    ls.pop_front();
    ls.pop_front();

    ls.test();
    ls.remove(ls.find(2));
    ls.test();

    return 0;
}