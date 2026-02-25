#include <iostream>

char foo(char c) {
    return c;
}

int main() {
    int n = 10;
    int i = 0;
    char* s = new char[n];
    char ch;
    while ((ch = std::cin.get())!='\n' && ch != EOF) {
        if (i+1 >= n) {
            n = n*2;
            char *current = new char[n];
            for (int j = 0; j < n; j++) {
                current[j] = s[j];
            }
            delete[] s;
            s = current;
        }
        s[i++] = ch;

    }
    std::cout << s << std::endl;
    delete[] s;
    return 0;
}