#include <iostream>

using namespace std;

void foo(int*& pp) {
    cout << &pp << endl;
    *pp = 11;
}

int main() {
    int* n =nullptr;
    int data(3);
    n = &data;
    cout << &n <<  endl;

    foo(n);
    cout << *n << endl;
    cout << &n <<  endl;

    return 0;
}