#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n) {
    int result = 1;
    if (n == 0) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

float power(float x, int k) {
    if (x == 1) return 1;
    if (x == 0){return 0;}
    float result = 1;
    for (int i = 1; i <= k; i++) {
        result *= x;
    }
    return result;
}

float cosi(float x) {
    double eps = 1e-6;
    double result = 0.0;
    int factor = 0;
    int i = 2;
    while (fabs(cos(x) - (1-result)) > eps) {
        result += power(-1.0, factor)*(power(x,i)/factorial(i));
        factor++;
        i+=2;
    }
    return 1-result;
}

float summ(float x, int n) {
    float y = 1;
    for (int i = 1; i <= n; i++) {
        y += power(x/(x+5), i)*cosi(i*x);
    }
    return y;
}

int main() {
    float x = 0.0, res = 0.0;
    int n = 0;
    cout << "Введите значене x: ";
    cin >> x;
    cout << "Введите значене n: ";
    cin >> n;
    res = 1 - 2*summ(x, n);
    cout << res;
    return 0;
}