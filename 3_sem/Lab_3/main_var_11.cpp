#include <iostream>

int get_len(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void copy(char* from, char* to) {
    int len = get_len(from);
    for (int i = 0; i < len; i++) to[i] = from[i];
}

char* getting() {
    int copasity = 10;
    int i = 0;
    char c;
    char* str = new char[copasity];
    std::cout << "Enter string: ";
    while ((c = std::cin.get()) != '\n') {
        if (i+1 >= copasity) {
            copasity *= 2;
            char* temp = new char[copasity];
            copy(str, temp);
            delete[] str;
            str = temp;
        }
        str[i++] = c;
        str[i] = '\0';
    }
    return str;
}

int linear_search(char* s, char* pattern, int start = 0) {
    const int len = 8;
    int str_len = get_len(s);
    // char pattern[] = "password";

    if (str_len < len) return -1;
    if (start > str_len - len) return -1;

    for (int i = start; i <= str_len - len; i++) {
        bool match = true;

        for (int j = 0; j < len; j++) {
            if (s[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            return i;
        }
    }

    return -1;
}

void search_and_switch(char* str, char* pattern) {
    const int len = 8;
    int str_len = get_len(str);

    int pos = linear_search(str, pattern);

    while (pos != -1) {

        int start_replace = pos;


        if (start_replace + len <= str_len) { //aapassword12345678aapassword87654321

            for (int i = 0; i < len; i++) {//password
                str[start_replace + i] = '*';
            }
        }

        pos = linear_search(str, pattern,pos + len);
    }
}

int main() {
    char *str = getting();
    char *pattern = getting();
    search_and_switch(str, pattern);
    std::cout << "Res:" << str << std::endl;
    return 0;
}