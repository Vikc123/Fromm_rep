#include <iostream>
using namespace std;

template<typename T>
class SmartPointer {
private:
    T *p;
public:
    SmartPointer(T* p) {
        this->p = p;
    }
    ~SmartPointer() {
        delete p;
    }
    T& operator* () {
        return *p;
    }
    template<typename U>
    friend ostream& operator<<(ostream& o,const SmartPointer<U> &p);
};
    template<typename T>
    ostream& operator<<(ostream& o,const SmartPointer<T>& p) {
        o << p.p;
        return o;
    }


int main() {
    int* n = new int(3);
    cout<< "Адрес: " << n << " " << "Содержимое: " << *n <<  endl;
    delete n;
    SmartPointer<int> p1 = new int(4);
    cout << "Адрес: " << p1 << " " << "Содержимое: " << *p1 << endl;
    return 0;
}

