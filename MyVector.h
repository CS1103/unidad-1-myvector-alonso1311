//
// Created by ALONSO on 27/08/2019.
//

#ifndef SEMANA2_MYVECTOR_MYVECTOR_H
#define SEMANA2_MYVECTOR_MYVECTOR_H


class MyVector {
private:
    int size;
    int* vector;

public:
    MyVector();
    MyVector(int);

    int getSize();
    void push_back(int);
    void insert(int, int);
    void pop_back();
    void erase(int);
    int operator[](int);
    friend MyVector& operator+(const MyVector&, const MyVector&);

    virtual ~MyVector();

};


#endif //SEMANA2_MYVECTOR_MYVECTOR_H
