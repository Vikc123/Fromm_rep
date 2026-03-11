// #include <cstdio>
// #include <iostream>
// #include <ostream>
//
// class A {
//     private:
//     int* n;
//     int size;
//     public:
//     A(int size) {
//         this->size = size;
//         this->n = new int[size];
//         for (int i = 0; i < size; i++) {
//             this->n[i] = i;
//         }
//         for (int i = 0; i < size; i++) {
//             std::cout << this->n[i] << " ";
//         }
//     }
//     A(const A& rhs) {
//         size = rhs.size;
//         this->n = new int[size];
//         for (int i = 0; i < size; i++) {
//             this->n[i] = rhs.n[i];
//         }
//         for (int i = 0; i < size; i++) {
//             std::cout << this->n[i] << " ";
//         }
//
//     }
//     ~A() {
//         delete[] this->n;
//     }
// };
//
// int main() {
//     A a(4);
//     A b(a);
//
//     return 0;
// }



// #include <iostream>
// #include <string>
//
// class FLOAT {
//     private:
//     int numerator;
//     int denominator;
//     public:
//     void operator >> (std::string fl) {
//         std::string num;
//         std::string den;
//         bool flag = true;
//         for (int i = 0; i < fl.length(); i++) {
//             if (fl[i] == '/') {
//                 flag = false;
//                 continue;
//             }
//             if (fl[i] != '/' || flag) {
//                 num += fl[i];
//             }
//             else {
//                 den += fl[i];
//             }
//         }
//         this ->numerator = stoi(num);
//         this -> denominator = stoi(den);
//     }
//     void operator << (std::string fl) {
//         float res = this -> numerator/ this -> denominator;
//         std::cout << res << std::endl;
//     }
// };
//
// int main() {
//     FLOAT f;
//     f >> "2/4";
//     f << "";
//     return 0;
// }

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Float {
    private:
    float numerator;
    float denominator;
    public:
    friend istream& operator>> (istream& is, Float& f);
    friend ostream& operator<< (ostream& o, Float& f);
    friend Float operator*(Float& a, Float& b);
};
//
// ostream& operator<< (ostream& o, Float& f) {
//     o << f.numerator/f.denominator;
//     return o;
// }
//
// istream& operator>> (istream& is, Float& f) {
//     std::string str;
//     std::string token;
//     std::string dtoken;
//     is >> str;
//     bool flag = true;
//     for (int i = 0; i < (int)str.length(); i++) {
//         if (flag) {
//                 if (str[i] == '/') {
//                     flag = false;
//                     continue;
//                 } else {
//                     token.push_back(str[i]);
//                     continue;
//                 }
//         } else {
//             for (int i = (int)token.length(); i > 0; i--) {
//                 f.numerator += (float)((int)token[i] - '0')*(pow(10, (int)token.length() - i));
//             }
//             token.clear();
//             dtoken.push_back(str[i]);
//             continue;
//         }
//         for (int i = (int)token.length(); i > 0; i--) {
//             f.denominator += (float)((int)token[i] - '0')*(pow(10, (int)token.length() - i));
//         }
//     }
//     return is;
// }
istream& operator>>(istream& is, Float& f)
{
    string str;
    is >> str;

    size_t pos = str.find('/');

    f.numerator = stof(str.substr(0, pos));
    f.denominator = stof(str.substr(pos + 1));

    return is;
}

Float operator*(Float& a, Float& b) {
    Float result;
    result.numerator = a.numerator*b.numerator;
    result.denominator = a.denominator*b.denominator;
    return result;
}

int main() {
    Float num, num_2;
    cin >> num;
    cout << num << endl;
    cin >> num_2;
    cout << num_2 << endl;
    // Float num_3 = num*num_2;
    // cout << num_3 << endl;
    return 0;
}