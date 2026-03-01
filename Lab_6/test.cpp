#include <iostream>
#include <list>
#include <random>



class A {
    private:
    int x;
    int y;
    public:
    A() {
        x = std::rand()%100;
        y = std::rand()%100;

    }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return this->x; }
    int getY() { return this->y; }
    void print() { std::cout << this->x << " " << this->y << std::endl; }
};

class B {
    private:
    std::list<A> a;
    public:
    void addA(A a) { this->a.push_back(a); }
    void print_list() {
        for (std::list<A>::iterator it = this->a.begin(); it != this->a.end(); it++) {
            std::cout << (*it).getX() << " " << (*it).getY() << std::endl;
        }
    }

};

class C {
    private:
    B* b;
    public:
    C(B* b) {
        this->b = b;
    }
    void addA(A a) {
        this->b->addA(a);
    }
};

int main() {
    std::srand(std::time(nullptr));
    B b;
    C c(&b);
    for (int i = 0; i < 5; i++) {
        A a;
        c.addA(a);
    }
    b.print_list();
    return 0;
}