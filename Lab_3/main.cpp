#include <iostream>

char foo(char c) {
    return c;
}

int main() {
    char c;
    c = 'f';
    std::cout << foo(c);
    return 0;
}