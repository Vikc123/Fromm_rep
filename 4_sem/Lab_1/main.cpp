#include <iostream>
#include "set.h"

using namespace std;

int main() {
    set<int> t;
    // cout << "создали дерево" << endl;
    t.insert(5);
    t.insert(4);
    t.insert(3);
    t.insert(5);
    t.insert(3);
    t.print_i();
    // set<int>::reverse_iterator it = t.rbegin();
    // it++;
    // it++;
    // cout << *it << endl;
    return 0;
}