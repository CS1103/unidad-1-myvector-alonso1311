//
// Created by ALONSO on 27/08/2019.
//

#include "MyVector.h"

MyVector::MyVector() : vector{nullptr}, size{0}{

}

MyVector::MyVector(int n) : size{n} {
    vector = new int[size];
}

MyVector::~MyVector() {
    delete [] vector;
}

int MyVector::getSize() {
    return size;
}

void MyVector::push_back(int number) {
    int *temp = new int[size+1];
    for (int i = 0; i < size; ++i) {
        temp[i] = vector[i];
    }
    delete [] vector;
    vector = temp;
    vector[size] = number;

    size++;

}

void MyVector::insert(int number, int index) {
    int *temp = new int[size+1];
    for (int i = 0; i < index; ++i) {
        temp[i] = vector[i];
    }

    temp[index] = number;

    for (int i = size; i > index; --i) {
        temp[i+1] = vector[i];
    }

    size++;
    delete [] vector;

    vector = temp;
}

void MyVector::pop_back() {
    int *temp = new int[size-1];
    for (int i = 0; i < size-1; ++i) {
        temp[i] = vector[i];
    }

    size = size-1;
    delete [] vector;

    vector = temp;
}

void MyVector::erase(int index) {
    for (int i = index; i < size; ++i) {
        vector[i] = vector[i+1];
    }

    size--;
}

int MyVector::operator[](int index) {
    return vector[index];
}

MyVector &operator+(const MyVector & v1, const MyVector & v2) {
    int total_size = v1.size + v2.size;

    int *temp = new int[total_size];
    for (int i = 0; i < v1.size; ++i) {
        temp[i] = v1.vector[i];
    }

    for (int i = v1.size; i < v2.size; ++i) {
        temp[i] = v2.vector[i-v1.size];
    }

    MyVector v3;
    for (int j = 0; j < total_size; ++j) {
        v3.vector[j] = temp[j];
    }
    return v3;
}
