#include <iostream>
#include "flow.h"
#include "encryption.h"

int main() {
    int ch = 'B';
    std::string str = "ABC\0";
    write_flow(str);
    rewrite_flow("df");
    str = read_flow("Lab_4/data/input.txt");
    std::cout << str << std::endl;
    std::cout << ch - 'A' + 1<< std::endl;
    encryption(str);
    return 0;
}