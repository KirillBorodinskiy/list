#ifndef LIST_H
#define LIST_H

#include "element.h"
class Iterator;
class ListIterator;
class List {
    Element *first;
    Element *last;
    unsigned int counter;

    void initList();

    void copyDataFrom(List &source);

    Element *find(Data d);

    static void swap(Element *a, Element *b);

public:

    List();

    List(List &other);

    ~List();

    void clear();

    Element *findMin(Element *elem);
    void sort();
    void pushBack(Data d);

    void pushFront(Data d);

    unsigned int size() const {
        return counter;
    }

    bool isEmpty() const {
        return !size();
        //return counter == 0;
    }

    void popFront();

    void popBack();

    Data front() const {
        return first->next->getData();
    }

    Data back() const {
        return last->prev->getData();
    }

    void print() const;

    void append(List &other) {
        this->copyDataFrom(other);
    }

    bool remove(Data d);
    friend class ListIterator;

    ListIterator *getIterator();
};


#endif // LIST_H
