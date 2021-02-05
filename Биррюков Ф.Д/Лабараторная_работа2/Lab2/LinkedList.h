#pragma once
#ifndef null
#define null nullptr
#endif
#include <iostream>

using namespace std;

struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int value;

    Node(int value) {
        this->value = value;
    }

    Node(int value, Node* next, Node* prev) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

struct LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        if (!head) {
            head = new Node(value);
            tail = head;
            return;
        } else {
            Node* oldTail = tail;
            tail = new Node(value, nullptr, oldTail);
            oldTail->next = tail;
            return;
        }
    }

    bool add(int value, int index) {
        if (index < 0) return false;
        Node* curr = head;
        if (curr == null && index!=0) return false;

        if (index == 0) {
            if (!head) {
                add(value);
                return true;
            }
            head = new Node(value);
            head->next = curr;
            curr->prev = head;
            return true;
        } else {
            for (int i = 1; i<index; i++) {
                curr = curr->next;
                if (curr == null) {
                    return false;
                }
            }
            if (curr->next == null) {
                tail = new Node(value, null, curr);
                curr->next = tail;
                return true;
            } else {
                curr = curr->next;
                Node* next = new Node(curr->value, curr->next, curr);
                curr->value = value;
                curr->next = next;
                if (tail->next != null) {
                    tail = tail->next;
                }
                return true;
            }
        }
    }

    Node* get(int index) {
        if (head == null) return null;
        Node* curr = head;
        for (int i = 1; i<=index; i++) {
            if (curr == null) return null;
            curr = curr->next;
        }
        return curr;
    }

    bool remove(int index) {
        Node* node = get(index);
        return removePtr(node);
    }

    bool removePtr(Node* node) {
        if (node == null) return false;

        if (head == tail) {
            head = null;
            tail = null;
            delete node;
            return true;
        }
        if (node == head) {
            head = head->next;
            head->prev = null;
            node->next = null;
            node->prev = null;
            delete node;
            return true;
        }
        if (node == tail) {
            tail = tail->prev;
            tail->next = null;
            node->next = null;
            node->prev = null;
            delete node;
            return true;
        }
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        node->next = null;
        node->prev = null;
        delete node;
        return true;
    }

    bool removeByValue(int value) {
        int i = 0;
        Node* node = head;
        while (node != null) {
            if (node->value == value) {
                cout << "Node:" << node << " Value:" << node->value << " index:" << i << endl;
                return removePtr(node);
            }
            node = node->next;
            i++;
        }
        return false;
    }

    void print() {
        cout << "Tail: " << tail << endl;
        cout << "Head: " << head << endl;
        Node* curr = head;
        while (curr != null) {
            cout << curr->prev << "<<[" << curr->value << "]>>" << curr->next <<endl;
            curr = curr->next;
        }
        cout << "end" << endl;
    }

    void freeMem() {
        Node* curr = head;
        while (curr) {
            Node* toRemove = curr;
            curr = curr->next;
            delete toRemove;
        }
    }
};