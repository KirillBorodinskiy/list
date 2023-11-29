//
// Created by kiril on 29.11.2023.
//
#include "vector.h"
#include <iostream>
#include <cstring>

Vector::Vector(unsigned int size) : cap(size), arr(new Data[size]) { memset(arr, 0, size * sizeof(Data)); }

Vector::Vector(Vector &v) : cap(v.cap), arr(new Data[v.cap]) {
    memcpy(this->arr, v.arr, v.cap * sizeof(Data));
}
Vector::~Vector(){
    delete[] arr;
}
Data& Vector::at(unsigned int index) {
    if (index >= cap) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}