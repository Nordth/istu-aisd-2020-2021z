#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Queue.h"

int main() {
    LinkedList* list = new LinkedList();
    for (int i = 0; i<5; i++) {
        list->add(i);
    }
    list->print();
    list->add(-1,0);
    list->print();
    list->remove(0);
    list->print();
    list->remove(4);
    list->print();
    for (int i = 0; i<5; i++) {
        list->add(i+5);
    }
    list->remove(1);
    list->remove(7);
    list->print();
    list->add(7, 6);
    list->print();
    list->removeByValue(116);
    list->removeByValue(7);
    list->print();
    list->removeByValue(8);
    list->print();

    Queue* que = new Queue();
    que->init(3);
    que->enqueue(1);
    que->dequeue();
    que->enqueue(1);
    que->dequeue();
    que->enqueue(1);
    que->enqueue(2);
    que->enqueue(1);
    for (int i = 0; i < 5; i++) {
        que->enqueue(i+5);
    }
    que->print();
    return 0;
}