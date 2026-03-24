#include <iostream>

using namespace std;

class weapon {
    public:
    virtual void shoot() = 0;
};

class gun : public weapon {
    public:
    void shoot() override {
        cout << "Bang" << endl;
    }
};

class mashingun : public gun {
    public:
    void shoot() override {
        cout << "Bang Bang Bang" << endl;
    }
};

class knife : public weapon {
    public:
    void shoot () override {
        cout << "VJUH" << endl;
    }
};

class Schoolshooter {
    public:
    void shoot(weapon* n) {
        n->shoot();
    }
};

int main() {
    Schoolshooter mm;
    gun* n;
    gun r ;
    n = &r;
    mm.shoot(n);
    mashingun* n1;
    mashingun r1 ;
    n1 = &r1;
    mm.shoot(n1);
    knife* n2;
    knife r2 ;
    n2 = &r2;
    mm.shoot(n2);
    return 0;
}