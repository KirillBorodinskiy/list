#include <iostream>
#include "list.h"
#include "queue.h"
#include "iterator.h"
#include "vector.h"

using namespace std;

Data getMinimum(Iterator *it) {
    Data min = it->data();
    while (it->next()) {
        if (it->data() < min) {
            min = it->data();
        }
    }
    return min;
}

int main() {
    Vector V(10);
    for(int i = 0;i<10;i++){
        cout<<V.at(i)<<" ";
        V.at(i)=i;
    }
    cout<<endl;
//    Queue q;
//    for(int i = 0;i<11;i++){
//        q.push(i);
//    }
//    while(!q.isEmpty()){
//        cout<<q.front()<<" ";
//        q.pop();
//    }
//
//
//    List l;
//    for (int i = 1; i < 11; i++) {
//        if (i % 2 == 0)
//            l.pushBack(i);
//        else
//            l.pushFront(i);
//
//    }
//    Iterator *it = l.getIterator();
//    while (it->next()) {
//        cout << it->data() << " ";
//    }
//    cout << endl;
//    cout << getMinimum(l.getIterator()) << endl;
//    l.print();
//    delete it;
    return 0;
}
