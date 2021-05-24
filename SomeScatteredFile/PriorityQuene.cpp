/**
 * Priority Quene, a kind of improved edition of normal FIFO quene.
 * Here I 'd like to use heap as the implement method.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef unsigned long long num;

template<typename Key, typename Value>
class PriorityQuene {
    
private:
    vector<pair<Key, Value>> heap;

    // Only avaliable when class Key has overloaded the operator <.
    typedef bool (*compareFunction)(const Key& k1, const Key& k2);
    compareFunction compare;
    num parent(num ix)const {
        if (ix == 0) {
            throw "Heap top element has no parent.";
        }else{
            return (ix - 1) / 2;
        }
    }
    num leftChild(num ix)const { return ix * 2 + 1; }
    num rightChild(num ix)const { return ix * 2 + 2; }
    Key& key(num ix) { return heap[ix].first; }
    static bool defaultCompare(const Key& a, const Key& b) { return a < b; }

    void heapify(num root, bool (*cmp)(const Key& k1, const Key& k2));
    
public:
    explicit PriorityQuene(compareFunction Comprae = &defaultCompare);
    num size()const { return heap.size(); }
    bool isEmpty()const { return heap.empty(); }
    const pair<Key, Value>& highestPriority() const{ return heap.front(); }
    void insert(const Key& k, const Value& val);
    // Remove the highest priority element of the quene.
    pair<Key, Value> pop();

    void test()const {
        for (auto& item : heap) {
            cout << item.first << "  ";
        }
        cout << endl;
    }
};

template<typename Key, typename Value>
PriorityQuene<Key, Value>::PriorityQuene(compareFunction Compare) :heap(), compare(Compare) {}

template<typename Key, typename Value> void
PriorityQuene<Key, Value>::heapify(num root, bool (*cmp)(const Key& k1, const Key& k2)) {
    if (root > heap.size() || root < 0) {
        throw "Index overflow at 'heapify.'";
    }

    // Make the root element settlement.
    auto xx_est{ root };// The largest or smallest one.
    auto lch{ leftChild(root) }, rch{ rightChild(root) };
    if (lch < size() && cmp(key(root), key(lch))) {
        xx_est = lch;
    }
    if (rch < size() && cmp(key(root), key(rch))) {
        xx_est = rch;
    }

    if (xx_est != root) {
        auto tmp{ key(root) };
        key(root) = key(xx_est);
        key(xx_est) = tmp;
        heapify(xx_est, cmp);
    }
}

template<typename Key, typename Value> void
PriorityQuene<Key, Value>::insert(const Key& k, const Value& val) {
    heap.push_back(pair<Key, Value>(k, val));
    auto subTree{ size() - 1 };
    // Find the suitable root that the new key could belong to.
    while (subTree != 0 && compare(heap[parent(subTree)].first, k)) {
        // Swap
        auto tmp{ heap[subTree] };
        heap[subTree] = heap[parent(subTree)];
        heap[parent(subTree)] = tmp;
        
        subTree = parent(subTree);
    }
}

template<typename Key, typename Value> pair<Key, Value>
PriorityQuene<Key, Value>::pop() {
    if (isEmpty()) {
        throw "The quene has no element to pop out.";
    }
    // swap
    auto rtn{ heap.front() };
    heap.front() = heap.back();
    heap.pop_back();
    heapify(0, compare);

    return rtn;
}

int main() {
    PriorityQuene<int, int> Q;
    Q.insert(1, 1);
    Q.insert(2, 1);
    Q.insert(3, 1);
    Q.insert(4, 1);
    Q.insert(5, 1);
    Q.insert(6, 1);
    Q.insert(7, 1);
    Q.insert(8, 1);
    Q.insert(9, 1);
    Q.insert(20, 1);
    Q.insert(21, 1);
    Q.insert(22, 1);
    Q.pop();
    Q.pop();
    
    Q.test();
    return 0;
}