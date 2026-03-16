#include <iostream>

using namespace std;

class Gun {
    public:
    virtual void shoot() {
        cout << "Piu" << endl;
    }
};

class Submashingun : public Gun {
    public:
    void shoot() override {
        cout << "Piu Piu Piu" << endl;
    }
};

class Schoolshooter {
    public:
    void shoot(Gun* weapon) {
        weapon->shoot();
    }
};

int main() {
    Gun* pm;
    Submashingun s;
    Schoolshooter mm;
    pm = &s; // базовый класс может ссылаться на любого своего потомка
    mm.shoot(pm);

    return 0;
}