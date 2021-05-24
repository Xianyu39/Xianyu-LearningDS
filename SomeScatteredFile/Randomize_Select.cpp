#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

inline void mySwap(int& a, int& b) {
    auto tmp{ a };
    a = b;
    b = tmp;
}
inline int partition(int arr[], int begin, int end) {
    int l{ begin - 1 }, r{ begin };
    while (r < end - 1) {
        if (arr[r] < arr[end - 1]) {
            mySwap(arr[r], arr[++l]);
        }
        ++r;
    }
    mySwap(arr[++l], arr[end - 1]);
    return l;
}
inline int randomizedPartition(int arr[], int begin, int end) {
    srand(time(nullptr));
    auto flag{ rand() % (end - begin) + begin };
    mySwap(arr[flag], arr[end - 1]);
    
    return partition(arr, begin, end);
}

int randomizedSelect(int arr[], int begin, int end, int n) {
    auto key{ randomizedPartition(arr, begin, end) };
    if (key > n) {
        end = key;
    }
    else if (key < n) {
        begin = key + 1;
    }
    else// key == n
    {
        return arr[key];
    }
}

int main() {
    int a[]{ 3,4,5,2,1,8,9,2 };
    cout << randomizedSelect(a, 0, 8, 3);
    return 0;
}