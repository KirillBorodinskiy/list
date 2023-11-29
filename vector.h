//
// Created by kiril on 29.11.2023.
//

#ifndef LIST_VECTOR_H
#define LIST_VECTOR_H

#include "element.h"

class Vector{
    unsigned int cap;
    Data *arr;
public:
    Vector(unsigned int size);
    Vector(Vector& v);
    ~Vector();
    Data& at(unsigned int index);
    unsigned int getSize() const{return cap;}
    Data& operator[](unsigned int index){return this->at(index);}
};
#endif //LIST_VECTOR_H
