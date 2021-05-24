#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

inline int parent(int ix) { return (ix - 1) / 2; }
inline int lchild(int ix) { return ix * 2 + 1; }
inline int rchild(int ix) { return lchild(ix) + 1; }

constexpr inline int None() { return -1; }

void get_Series(int arr[], int idx, int N, vector<int> srs) {
    static int num{ 1 };
    srs.push_back(arr[idx]);
    if (arr[lchild(idx)] != None()) {
        get_Series(arr, lchild(idx), N - 1, srs);
    }
    else if (arr[rchild(idx)] != None()) {
        get_Series(arr, rchild(idx), N - 1, srs);
    }
    else {
        arr[idx] = None();
        // print
        cout << num++ << ":";
        for (auto i : srs) {
            cout << i << ',';
        }
        cout << '\b' << endl;
    }
}

void arrange(int arr[], int idx, int N, int& tree_count) {
    vector<int> s{  };
    for (size_t i = 0; i < 14; i++)
    {
        get_Series(arr, idx, N, s);
    }
    
    for (int i = 0; i < 31; i++)
    {
        cout << arr[i];
    }

}

int main() {
    int a4[]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    // int at[]{ 1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    // int a3[]{ 1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1 };
    int i;
    arrange(a4, 0, 4, i);
    cout << i;
    return 0;
}