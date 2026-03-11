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
    std::list<A*> a;
    public:
    void addA(A *a) { this->a.push_back(a); }
    void print_list() {
        for (std::list<A*>::iterator it = this->a.begin(); it != this->a.end(); it++) {
            std::cout << (*it)->getX() << " " << (*it)->getY() << std::endl;
        }
    }
    void deleteA(int num) {
        std::list<A*>::iterator it = a.begin();
        std::advance(it, num);
        a.erase(it);
    }
};

    class C;
    class D;
    class E;


class F {
protected:
    std::string name;
public:
    virtual void setName(std::string name) = 0;
    void getName() { std::cout << this->name; }
};


class C : public F {
    private:
    B* b;
    public:
    C(B* b) {
        this->b = b;
    }
    void addA(A *a) {
        this->b->addA(a);
    }

    void deleteA(int n) {
        this->b->deleteA(n);
    }
    void print_list() {
        this->b->print_list();
    }
    void setName(std::string name) override { this->name = name;; }
};

class D : public F{
private:
    std::list<E*> e;
public:
    void setName(std::string name) override { this->name = name;; }
};

class E : public F{
private:
    D* d;
public:
    void setName(std::string name) override { this->name = name;; }
};


int main() {
    std::srand(std::time(nullptr));
    B b;
    C c(&b);
    for (int i = 0; i < 5; i++) {
        A *a = new A();
        c.addA(a);
    }
    c.print_list();
    std::cout << std::endl;
    int n = 4;
    c.deleteA(n);
    c.print_list();
    D d;
    d.setName("D");
    d.getName();

    return 0;
}