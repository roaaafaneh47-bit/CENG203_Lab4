#include "Queue.h"
#include <iostream>
using namespace std;
Queue::Queue() : front(nullptr), rear(nullptr), count(0) {}
Queue::~Queue() { int v; while (dequeue(v)) {} }
void Queue::enqueue(int value) {
    Node* n = new Node(value);
    if (isEmpty()) front = rear = n;
    else { rear->next = n; rear = n; }
    ++count;
}
bool Queue::dequeue(int& value) {
    if (isEmpty()) return false;
    Node* temp = front;
    value = temp->data;
    front = front->next;
    delete temp;
    --count;
    if (front == nullptr) rear = nullptr;
    return true;
}
bool Queue::peek(int& value) const {
    if (isEmpty()) return false;
    value = front->data;
    return true;
}
bool Queue::isEmpty() const { return front == nullptr; }
int Queue::size() const { return count; }
void Queue::display() const {
    cout << "front ->";
    for (Node* n=front;n!=nullptr;n=n->next) cout << " " << n->data;
    if (isEmpty()) cout << " (empty)";
    cout << " <- rear" << endl;
}
