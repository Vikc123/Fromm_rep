#include <iostream>
#include "flow.h"
#include "encryption.h"
#include "decryption.h"

int main() {
    int ch = 'B';
    std::string str = "FGFGFGFG";
    write_flow(str, "Lab_4/data/input.txt");
    str = read_flow("Lab_4/data/input.txt");
    encryption(str);
    decryption("Lab_4/data/encrypted.txt");
    return 0;
}