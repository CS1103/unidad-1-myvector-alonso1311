#include <iostream>
#include <cassert>
#include "MyVector.h"
#include "MyVector.cpp"

using namespace std;

int main() {
    MyVector v1;

    assert(v1.getSize() == 0);

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    v1.push_back(70);

    cout << v1.getSize() << endl;

    for (int i = 0; i < v1.getSize(); ++i) {
        cout << v1[i] << endl;
    }

    cout << endl;

    v1.erase(3);

    cout << v1.getSize() << endl;

    for (int i = 0; i < v1.getSize(); ++i) {
        cout << v1[i] << endl;
    }

    v1.insert(100,4);
    cout << endl;

    cout << v1.getSize() << endl;

    for (int i = 0; i < v1.getSize(); ++i) {
        cout << v1[i] << endl;
    }

    MyVector v2;
    v2.push_back(12);
    v2.push_back(13);
    v2.push_back(14);

    MyVector v3(v1.getSize()+v2.getSize());
    v3 = v1 + v2;
    cout << endl << "Suma:";
    for (int i = 0; i < v3.getSize(); ++i) {
        cout << v3[i] << endl;
    }

    assert(v3.getSize() == 3);

    string resultado;
    try {
        v1.insert(10, 10);
    }
    catch (const exception& e) {
        resultado = e.what();
    }
    assert(resultado =="Fuera de limite");

    return 0;
}