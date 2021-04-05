#include <iostream>
using namespace std;

class Loop_Queue{
private:
    // Keep one place empty, the max size actually is max_size-1
    size_t max_size = 8;
    int *arr;
    size_t front;
    size_t rear;
    size_t length;

public:
    Loop_Queue(size_t max_size = 101): front(0), rear(0), length(0), max_size(max_size) {
        arr = new int[max_size];
        for (auto i{0}; i < max_size; ++i) {
            arr[i] = int();
        }
    }

    ~Loop_Queue(){
        if(!arr){
            delete[] arr;
        }
        arr = nullptr;
    }
    size_t size() const { return length; }
    bool empty() const { return !length; }

    // return status
    bool push(int val){
        // Examine whether it is almost full.
        if (length == max_size - 1) {
            return false;
        }

        // Insert
        arr[rear] = val;
        ++length;

        // Move
        if (rear == max_size - 1){
            rear = 0;
        }else{
            ++rear;
        }
        return true;
    }

    bool pop(){
        // Examine whether it is empty.
        if (length == 0) {
            return false;
        }
        // remove
        if (front == max_size - 1)
            front = 0;
        else
            ++front;
        --length;
        return true;
    }

    void test(){
        size_t ix{front};
        while (ix != rear){
            cout << arr[ix] << ' ';
            if (ix == max_size - 1){
                ix = 0;
            }else{
                ++ix;
            }
        }
        cout << endl
             << "front: " << front << endl
             << "rear: " << rear << endl
             << "Length: " << size() << endl;
    }
};

int main(){
    Loop_Queue ls;
    ls.push(1);
    ls.push(2);
    ls.push(3);
    ls.push(4);
    ls.push(5);
    ls.push(6);
    ls.push(7);
    ls.push(8);
    // ls.test();

    ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();

    // ls.test();

    ls.push(9);
    ls.push(10);
    ls.push(11);
    ls.push(6);
    ls.push(7);
    ls.push(8);
    ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();

ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();

ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();
ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();
    ls.push(9);
    ls.push(10);
    ls.push(11);
    ls.push(6);
    ls.push(7);
    ls.push(8);

    ls.test();

    return 0;
}