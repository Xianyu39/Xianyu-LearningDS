#include <iostream>
#include <stdint.h>
#include <string>
using namespace std;

int* binary_search(int* begin, int* end, int key) {
    while (end - begin > 1) {
        auto mid{ begin + (end - begin) / 2 };
        if (*begin == key) return begin;
        if (*mid == key) return mid;
        if (key > *mid) {
            begin = mid;
        }
        else {
            end = mid;
        }
    }
    return begin; // Not found, return the closest but smaller one.
}

class Sort {
public:
    using size_t = long long;
    using compareFunction = bool (*)(int, int);

    static bool df_compare(int a, int b) { return a < b; }
    // Merge 2 sorted series.
    static void merge(int* begin, int* mid, int* end,
        compareFunction compare = df_compare) {
        const auto n1{ mid - begin }, n2{ end - mid }; // 2 new arrays' length.
        // Make 2 transcripts.
        int l1[n1], l2[n2];
        for (int i{ 0 }; i < n1; ++i) {
            l1[i] = begin[i];
        }

        for (int i{ 0 }; i < n2; ++i) {
            l2[i] = mid[i];
        }

        // Merge
        int i{ 0 }, j{ 0 }, k{ 0 };
        for (; i < n1 && j < n2; ++k) {
            if (compare(l1[i], l2[j])) {
                begin[k] = l1[i];
                ++i;
            }
            else {
                begin[k] = l2[j];
                ++j;
            }
        }
        if (i == n1) {
            for (; j < n2; ++j, ++k) {
                begin[k] = l2[j];
            }
        }
        if (j == n2) {
            for (; i < n1; ++i, ++k) {
                begin[k] = l1[i];
            }
        }
    }

    void Bubble_sort(int* begin, int* end, compareFunction compare = df_compare) {
        size_t size{ end - begin };
        for (size_t i{ 0 }; i < size - 1; ++i) {
            for (size_t j{ size - 1 }, k{ j - 1 }; j > i; --j, --k) {// The Bubble
                if (compare(begin[j], begin[k])) {
                    // Swap 2 values.
                    auto tmp{ begin[j] };
                    begin[j] = begin[k];
                    begin[k] = tmp;
                }
            }
        }
    }
    void Selection_sort(int* begin, int* end, compareFunction compare = df_compare) {
        size_t size{ end - begin };
        for (size_t i{ 0 }; i < size - 1; ++i) {
            for (size_t j{ i + 1 }; j < size; ++j) {
                if (compare(begin[j], begin[i])) {
                    auto tmp{ begin[j] };
                    begin[j] = begin[i];
                    begin[i] = tmp;
                }
            }
        }
    }
    void Insertion_sort(int* begin, int* end, compareFunction compare = df_compare) {
        for (auto i{ 1 }; i < end - begin; ++i) {
            auto tmp{ begin[i] };
            // Find the suitable place and insert.
            auto j{ i - 1 };
            while (j >= 0 && compare(tmp, begin[j])) {
                begin[j + 1] = begin[j];
                --j;
            }
            begin[j + 1] = tmp;
        }
    }

    void Insertion_sort_Recurition(int* begin, int* end,
        compareFunction compare = df_compare) {
        if (--end - begin > 1) {
            Insertion_sort_Recurition(begin, end);
        }
        int* p = end - 1;
        int tmp = *end;
        while (p >= begin && compare(tmp, *p)) {
            *(p + 1) = *p;
            p--;
        }
        *(p + 1) = tmp;
    }

    void Merge_sort(int* begin, int* end, compareFunction compare = df_compare) {
        if (begin < end - 1) { // When two pointers are neighboring, stop.
            auto mid{ begin + (end - begin) / 2 };
            Merge_sort(begin, mid, compare);
            Merge_sort(mid, end, compare);
            merge(begin, mid, end, compare);
        }
    }
    template <class Type> using compare = bool (*)(const Type& a, const Type& b);
    template<class Type = int>
    void Quik_sort(Type* begin, Type* end) {
        if (begin < end - 1) {
            // PARTITION
            auto flag{ *(end - 1) };
            size_t i{ -1 }, j{ 0 };
            while (j < end - begin) {
                if (begin[j] < flag) {
                    ++i;
                    // Swap
                    auto tmp{ begin[i] };
                    begin[i] = begin[j];
                    begin[j] = tmp;
                }
                ++j;
            }
            // Swap
            auto tmp{ begin[i + 1] };
            begin[i + 1] = *(end - 1);
            *(end - 1) = tmp;

            Quik_sort<Type>(begin, begin + i + 1);
            Quik_sort<Type>(begin + i + 2, end);
        }
    }

    void Merge_Insertion_sort(int* begin, int* end,
        compareFunction compare = df_compare) {
        // k is a limit, defined when to use insertion sort. 
        static const int k{ 5 };
        if (end - begin > k) {
            auto mid{ begin + (end - begin) / 2 };
            Merge_Insertion_sort(begin, mid);
            Merge_Insertion_sort(mid, end);
            // Watch
            // for (int i{ 0 };i < end - begin;++i) {
            //     cout << begin[i] << ' ';
            // }
            // cout << endl;
            merge(begin, mid, end);
        }
        Insertion_sort(begin, end);
    }

    // Heap sort
    int parent(int ix) { return (ix - 1) / 2; }
    int lchild(int ix) { return ix * 2 + 1; }
    int rchild(int ix) { return lchild(ix) + 1; }
    void swap(int& a, int& b) {
        auto temp{ a };
        a = b;
        b = temp;
    }

    void max_heapify(int* begin, int* end, int root) {
        auto lkid{ lchild(root) };
        auto rkid{ rchild(root) };
        auto size{ end - begin };
        int largest{ root };
        if (lkid < size && df_compare(begin[lkid], begin[largest])) {
            largest = lkid;
        }
        if (rkid < size&& df_compare(begin[rkid], begin[largest])) {
            largest = rkid;
        }
        if (largest != root) {
            swap(begin[root], begin[largest]);
            max_heapify(begin, end, largest);
        }
    }
    void build_heap(int* begin, int* end) {
        auto non_leaf{ parent(end - begin - 1) };
        for (int i = non_leaf; i > -1; --i) {
            max_heapify(begin, end, i);
        }
    }
    void heap_sort(int* begin, int* end) {
        for (size_t i = 0; i < end - begin; i++) {
            build_heap(begin + i, end);
        }

    }
};

int main() {
    int arr[] = { 1, 34, 121, 45, 12, 34, 66, 88, 56, 12 , 1, -10, 12 };
    // Sort().Quik_sort(arr, arr+10);
    for (auto i : arr)
        cout << i << "  ";
    cout << endl;

    // Sort().heap_sort(arr, arr + 15);
    // for (auto& i : arr) {
    //     cout << i << "  ";
    // }
    // cout << endl;

    Sort().Quik_sort(arr, arr + 13);
    // Sort().max_heapify(arr, arr + 10, 0);
    for (auto& i : arr) {
        cout << i << "  ";
    }

    return 0;
}

