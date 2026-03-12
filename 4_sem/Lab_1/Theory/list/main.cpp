#include <iostream>
#include <list>

using namespace std;

template<typename T>
void PrintList(const list<T>& ls) {
    for (auto it = ls.begin(); it != ls.end(); it++) {
        cout << *it << " ";
    }
};


int main() {
    list<int> ls = {1, 3, 4, 6, 7, 8, 9, 10, 2, 5};
    PrintList(ls);
    list<int>::iterator it;
    ls.sort();
    PrintList(ls);

    return 0;
}