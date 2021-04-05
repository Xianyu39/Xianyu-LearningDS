#include <string>
#include <iostream>
#include <vector>
using namespace std;

int search(const string& str, const string& substr){
    vector<int> next;
    next.resize(substr.size());
    next[0] = -1;
    int i{0}, j{0};
    while(i < int(str.size()) && j < int(substr.size())){
        if(j==-1||str[i]==substr[j]){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }

    if(j == int(substr.size())){
        return i - j;
    }else
    {
        return -1;
    }
    
}

int main(){
    string s{"abcdex"}, t{"e"};
    cout << search(s, t);

    return 0;
}