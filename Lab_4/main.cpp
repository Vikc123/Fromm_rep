#include <iostream>
#include "flow.h"
int main() {
    std::string str = "Hello World of Humen!\n";
    write_flow(str);
    str = read_flow("Lab_4/data/input.txt");
    std::cout << str << std::endl;
    return 0;
}