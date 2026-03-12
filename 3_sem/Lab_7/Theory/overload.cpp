#include <iostream>

using namespace std;

class num {
private:
    int value;
public:
    num(int value) {
        this->value = value;
    }
    void display() {
        cout << this->value << endl;
    }
    bool operator<(num& other) { // определение внутри класса
        return this->value < other.value;
    }
    int operator+(num& other) {
        return this->value + other.value+1;
    }
    num operator++(int) {
        num temp = *this;  // num operator++(int) - сигнатура постфикса(только для того чтобы компилятор различал постфикс и
        this->value++; // и префикс)
        return temp;
    }
    // ostream& operator<<(ostream& os) {
    //     os << this->value;// писать так можно, но вызывать тогда придется a << cout;
    //     return os;
    // }
    friend ostream& operator<<(ostream& os, num& a); //так пишется для того чтобы перегрузить как бинарную операцию

    num& operator++() {
        this->value++;
        return *this;
    }
    ~num() {
    }
};

ostream& operator<<(ostream& os, num& a) {
    os << a.value;
    return os;
}

class num2 {
public:
    int value;
    num2(int value) {
        this->value = value;//переопределение вне класса
    }
    ~num2() {

    }
};
bool operator<(const num2& A, const num2& B) {
    return A.value < B.value;
};

class num3 {
private:
    int value;
    public:
    num3(int value) {
        this->value = value; // переопределение вне класса с помощью friend
    }
    ~num3() {
    }
    friend bool operator<(const num3& A, const num3& B);
};
bool operator<(const num3& A, const num3& B) {
    return A.value < B.value;
}




int main() {
    int a(3), b(23);
    bool res(a>b);
    num A(3), B(23);
    if (A<B) {
        cout <<"А меньше Б" << endl;
    }
    num c = A+B;
    c.display();
    c++;
    c.display();
    // ++c<<cout << endl;
    cout << ++c << endl;
    return 0;
}
