#include <iostream>
#include <ostream>
#include <set>

using namespace std;

int main() {
    set<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(40);
    tree.insert(20);
    tree.insert(60);
    tree.insert(80);
    set<int>::iterator it;
    for (it = tree.begin(); it != tree.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    //тк не константный, изменим какой-нибудь элемент
    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (*it == 3) {
        }
    }

    set<int>::reverse_iterator it2;
    for (it2 = tree.rbegin(); it2 != tree.rend(); it2++) {
        cout << *it2 << " ";
    }
    cout << endl;
    return 0;
}
