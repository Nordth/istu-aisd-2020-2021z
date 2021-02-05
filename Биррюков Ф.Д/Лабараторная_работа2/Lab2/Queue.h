#pragma once
#ifndef null
#define null nullptr
#endif
#include <iostream>

using namespace std;

struct Data {
    int value;
    int resultCode = 200;

    Data(int value, int code) {
        this->value = value;
        this->resultCode = resultCode;
    }
};

struct Queue {
    int capacity = 0;
    bool isInitialized = false;
    int* array = null;
    int first = 0;
    int last = 0;
    int size = 0;

    void init(int capacity) {
        if (isInitialized) return;
        this->capacity = capacity;
        this->isInitialized = true;
        this->array = new int[capacity];
    }

    void enqueue(int value) {
        if (size == capacity) {
            int* oldArray = array;
            int oldCapacity = capacity;
            capacity = capacity * 2;
            array = new int[capacity];
            int tempSize = size;
            int tempFirst = first;
            first = 0;
            last = 0;
            size = 0;
            while (tempSize > 0) {
                enqueue(oldArray[tempFirst++]);
                tempFirst = tempFirst % oldCapacity;
                tempSize--;
            }
        }
        array[last++] = value;
        last = last % capacity;
        size++;
    }

    Data* dequeue() {
        if (size == 0) {
            return new Data(-1, 404);
        }
        Data* data = new Data(array[first++], 200);
        first = first%capacity;
        size--;
        return data;
    }

    Queue* clone() {
        Queue* queue = new Queue();
        queue->capacity = this->capacity;
        queue->first = this->first;
        queue->size = this->size;
        queue->last = this->last;
        queue->isInitialized = true;
        queue->array = new int[capacity];
        for (int i = 0; i<capacity; i++) {
            queue->array[i] = this->array[i];
        }
        return queue;
    }

    void freeMem() {
        delete[] this->array;
        isInitialized = false;
        capacity = 0;
        size = 0;
        first = 0;
        last = 0;
        array = null;
    }

    void print() {
        int temp = size;
        int tempFirst = first;
        cout << "Head-> ";
        while (temp > 0) {
            cout << array[tempFirst++] << "[" << tempFirst << "]" << " ";
            tempFirst = tempFirst%capacity;
            temp--;
        }
        cout << "<-Tail" << endl;
    }
};