//
// Created by kiril on 29.11.2023.
//

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "list.h"


class Queue {
    List *list;
public:
    Queue(): list(new List) {};

    ~Queue(){delete list;};

    void push(Data d){list->pushBack(d);}

    Data front() const{return list->front();}

    void pop(){list->popFront();}

    bool isEmpty() const{return list->isEmpty();}
};


#endif //LIST_QUEUE_H
