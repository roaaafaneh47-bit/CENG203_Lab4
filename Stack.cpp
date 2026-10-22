#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack() : top(nullptr), count(0) {}
Stack::~Stack() { clear(); }
void Stack::push(int value) {
    Node* n = new Node(value);
    n->next = top;
    top = n;
    ++count;
}
bool Stack::pop(int& value) {
    if (isEmpty()) return false;
    Node* temp = top;
    value = top->data;
    top = top->next;
    delete temp;
    --count;
    return true;
}
bool Stack::peek(int& value) const {
    if (isEmpty()) return false;
    value = top->data;
    return true;
}
bool Stack::isEmpty() const { return top == nullptr; }
int Stack::size() const { return count; }
void Stack::clear() { int v; while (pop(v)) {} }
void Stack::display() const {
    cout << "top ->";
    for (Node* cur = top; cur != nullptr; cur = cur->next) cout << " " << cur->data;
    if (isEmpty()) cout << " (empty)";
    cout << endl;
}
