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
ostream& operator<< (ostream& o, Float& f) {
    o << f.numerator/f.denominator;
    return o;
}
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
    Float num_3 = num*num_2;
    cout << num_3 << endl;
    return 0;
}