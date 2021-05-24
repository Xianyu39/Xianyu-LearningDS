#include "include/List.hpp"
#include <string>

int main() {
    MyList::List<int> ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(10);
    ls.push_back(112);
    ls.push_back(21);
    ls.pop_back();
    ls.pop_back();
    ls.pop_front();
    ls.test();
    ls.push_back(89);
    ls.push_back(12);
    ls.test();
    ls.push_back(10);
    ls.push_back(9);
    ls.push_back(2);

    ls.test();

    return 0;
}