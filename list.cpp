#include "list.h"


List::List()
        : first(new Element()),
          last(new Element()),
          counter(0) {
    initList();
}

List::~List() {
    clear();
    delete first;
    delete last;
}

//copy elements from source list into this list
void List::copyDataFrom(List &source) {
    Element *iter = source.first->next;
    while (iter != source.last) {
        this->pushBack(iter->getData());
        iter = iter->next;
    }
}

List::List(List &other)
        : first(new Element), last(new Element),
          counter(0) {
    initList();
    copyDataFrom(other);
}

void List::clear() {
    while (!isEmpty()) {
        popFront();
    }
}

void List::initList() {
    first->next = last;
    last->prev = first;
}

void List::pushBack(Data d) {
    last->next = new Element;
    last->setData(d);
    last->next->prev = last;
    last = last->next;
    counter++;
}

/*
 * last <-> first
 * next <-> prev
*/
void List::pushFront(Data d) {
    first->prev = new Element;
    first->setData(d);
    first->prev->next = first;
    first = first->prev;
    counter++;
}

void List::popFront() {
    if (!isEmpty()) {
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
        counter--;
    }
}

void List::popBack() {
    if (!isEmpty()) {
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        counter--;
    }
}

void List::print() const {
    for (Element *iter = first->next;
         iter != last;
         iter = iter->next) {
        iter->print();
    }
}


Element *List::find(Data d) {
    last->setData(d);
    Element *iter = first->next;
    while (iter->getData() != d) {
        iter = iter->next;
    }
    return iter == last ? nullptr : iter;
}

bool List::remove(Data d) {
    Element *del = find(d);
    if (!del) {
        return del;
    }
    del->prev->next = del->next;
    del->next->prev = del->prev;
    delete del;
    counter--;
    return true;
}

void List::swap(Element *a, Element *b) {//Swapping the data of two elements
    Data temp = a->getData();
    a->setData(b->getData());
    b->setData(temp);
}

Element *List::findMin(Element *elem) {
    for (Element *temp = elem; temp != last; temp = temp->next) {//Searching through the list looking for the smallest element
        if (temp->getData() < elem->getData()) {
            elem = temp; //Now elem points to the smallest element
        }
    }
    return elem;
}

void List::sort() {
    for (Element *temp = first->next; temp->next != last; temp = temp->next) {
//        std::cout << "Current element: " << temp->getData() << " "; //Uncomment to see the swapping process
        swap(temp, findMin(temp));//Swapping the data of the current element with the smallest element
//        std::cout << " changed to -> " << temp->getData() << std::endl;

    }
}
