#pragma once
class ArrayStack {
    static const int CAPACITY = 5;
    int items[CAPACITY];
    int topIndex;
public:
    ArrayStack();
    bool push(int value);
    bool pop(int& value);
    bool peek(int& value) const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void display() const;
};
