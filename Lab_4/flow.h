#pragma once
#include <fstream>
#include <iostream>

void write_flow(std::string text) {
    std::ofstream file("Lab_4/data/output.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    file << text;
    file.close();
}

void rewrite_flow(std::string text) {
    std::ofstream file("Lab_4/data/output.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    file << text;
    file.close();
}

std::string read_flow(std::string from) {
    std::ifstream file(from);
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
    }
    std::string text;
    while (!file.eof()) {
        std::getline(file, text);
    }
    return text;
}
