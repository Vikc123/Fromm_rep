#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "flow.h"

void decryption(std::string from) {
    std::ifstream file(from);
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
    }
    std::string text;
    while (!file.eof()) {
        std::getline(file, text);
    }
    std::string token = "";
    std::string result = "";
    int numb;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            token += text[i];
        } else {
            numb = std::stoi(token);
            result += char(numb+64);
            token = "";
        }
    }
    std::cout << result << std::endl;
    write_flow(result, "Lab_4/data/output.txt");
}
