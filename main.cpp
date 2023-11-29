#include <iostream>
#include "list.h"
#include "queue.h"
using namespace std;

int main()
{
    Queue q;
    for(int i = 0;i<11;i++){
        q.push(i);
    }
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
//
//    List l;
//    for(int i = 0; i < 10; i++){
//        if(i % 2 == 0)
//            l.pushBack(i);
//        else
//            l.pushFront(i);
//
//    }
//    l.print();
//    cout<<endl;
//    l.sort();
//    l.print();
//    return 0;
}
