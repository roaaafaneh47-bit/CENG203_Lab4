#pragma once
#include "../LinkedList/Node.h"
class Stack {
    Node* top;
    int count;
public:
    Stack();
    ~Stack();
    void push(int value);
    bool pop(int& value);
    bool peek(int& value) const;
    bool isEmpty() const;
    int size() const;
    void clear();
    void display() const;
};
