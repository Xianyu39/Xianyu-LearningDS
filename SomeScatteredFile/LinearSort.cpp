#include<iostream>
#include<vector>
using namespace std;

// Assumme that only 0-9 number the arr includes.
void Count_Sort(int arr[], size_t begin, size_t end) {
    int* rslt{ new int[end - begin] };
    int msg[10];
    for (size_t i = 0; i < 10; i++){
        msg[i] = 0;
    }
    
    for (size_t i = begin; i < end; i++) {
        ++msg[arr[i]];
    }

    for (size_t i = 1; i < 10; i++) {
        msg[i] += msg[i - 1];
    }
    for (size_t i = begin; i < end; i++) {
        rslt[msg[arr[i]] - 1] = arr[i];
        --msg[arr[i]];
    }

    // Watch
    for (size_t i = 0; i < end - begin; i++) {
        cout << rslt[i] << ' ';
    }

    delete[] rslt;
}

void Bucket_Sort(double arr[], int begin, int end) {
    auto n{ end - begin };
    vector<double>* Buckets{ new vector<double>[n] };
    for (int i = 0; i < n; i++){
        Buckets[int(n * arr[i])].push_back(arr[i]);
    }
    
    delete[] Buckets;
}

size_t randomized_partition(int* begin, int* end) {
    
}

int main() {
    int a[]{ 4,3,5,6,2,7,8,2,9,1,1 };
    for (auto i : a) {
        cout << i << ' ';
    }
    cout << endl;
    Count_Sort(a, 0, 11);
    return 0;
}