#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout << "текущий вектор: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Количество заполненных ячеек вектора (size): " << v.size() << endl;
    //добавим пару новых ячкеек
    v.resize(6); // метод пересчитает длину вектора по формуле max(requation_copacity, old_copacity * 2), изменяется именно size
    cout << "Количество заполненных ячеек вектора (size): " << v.size() << endl;
    cout << "Размер вектора (copacity): " << v.capacity() << endl;
    v.shrink_to_fit(); //метод добьет размер вектора то актуального заполнения, изменяется copacity
    cout << "Количество заполненных ячеек вектора (size): " << v.size() << endl;
    cout << "Размер вектора (copacity): " << v.capacity() << endl;
    v.reserve(10);// добавили к copasity
    cout << "Количество заполненных ячеек вектора (size): " << v.size() << endl;
    cout << "Размер вектора (copacity): " << v.capacity() << endl;
    v.pop_back();//удалили последний
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    // cout << v.empty();
    // v.clear();
    // cout << v.empty();
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (vector<int>::const_iterator it = v.cbegin(); it < v.cend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (vector<int>::reverse_iterator it = v.rbegin(); it < v.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    it++;
    v.insert(it, 10);
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    advance(it,3);
    v.insert(it, 10);
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    vector<int>::iterator itErrase = v.begin();
    itErrase++;
    v.erase(itErrase);
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}