//
// Created by kiril on 29.11.2023.
//

#include "iterator.h"
#include "list.h"

void ListIterator::reset() {
    current = list->first;
}

ListIterator::ListIterator(List *list) : list(list), current(list->first) {}

Data &ListIterator::data() {
    return current->data;
}

bool ListIterator::next() {
    if (current == list->last) {
        current = list->first;
    }else{
        current = current->next;
    }
    return current != list->last;
}
