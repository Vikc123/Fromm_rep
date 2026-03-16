#include <iostream>
#include "set.h"

using namespace std;

int main() {
    set<int> t;
    cout << "создали дерево" << endl;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    set<int>::reverse_iterator it = t.rbegin();
    it++;
    it++;
    cout << *it << endl;
    return 0;
}