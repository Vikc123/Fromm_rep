#include <iostream>


int get_len(char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void copy_string(char *from, char *to) {
    int len = get_len(from);
    for (int i = 0; i < len; i++) {
        to[i] = from[i];
    }
}

void find_max(char* str) {
    char *max = new char[get_len(str)];
    char *token = new char[get_len(str)];
    int max_len  = 0;
    int current_len = 0;
    int index = 0;
    int token_index = 0;
    while (str[index] != '\n') {
        if (str[index] != ' ') {
            token[token_index++] = str[index++];
            current_len++;
            continue;
        } else {
            if (max_len < current_len) {
                copy_string(token, max);
                max_len = current_len;
            }
            current_len = 0;
            token_index = 0;
            index++;
        }

    }
    if (max_len < current_len) {
        copy_string(token, max);
        max_len = current_len;
        current_len = 0;
    }
    std::cout << "Самое длинное слово: " << max << std::endl;
    delete[] max;
    delete[] token;
}
char* getter () {
    int n = 10;
    int i = 0;
    char* s = new char[n];
    char ch;
    std::cout << "Enter a string: ";//я витя красавчик, а ты вита красавица
    while ((ch = std::cin.get())!='\n') {
        if (i+1 >= n) {
            n = n*2;
            char *current = new char[n];
            copy_string(s, current);
            delete[] s;
            s = current;
        }
        s[i++] = ch;
        s[i] = '\n';

    }
    return s;
}

int main() {
    char* str = getter();
    find_max(str);
    delete[] str;

    return 0;
}