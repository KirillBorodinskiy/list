//
// Created by kiril on 29.11.2023.
//

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "element.h"


class Iterator {
public:
    Iterator() {}

    virtual ~Iterator() {}

    virtual void reset() = 0;

    virtual Data &data() = 0;

    virtual bool next() = 0;
};

class List;

class ListIterator : public Iterator {
    List *list;
    Element *current;
public:
    ListIterator(List *list);
    virtual ~ListIterator() {};
    virtual void reset();
    virtual Data &data();
    virtual bool next();

};


//VectorIterator

#endif //LIST_ITERATOR_H
