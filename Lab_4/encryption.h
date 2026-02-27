#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include "flow.h"

int get_len(std::string str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void encryption(std::string str) {
    int len = get_len(str);
    std::string str1 = "";
    for (int i = 0; i < len; i++) {
        int c = str[i] - 'A'+1;
        str1.append(std::to_string(c));
        str1.append(" ");
    }
    write_flow(str1);
}
