#include "Labs.h"
#include "../Stack/Stack.h"
#include "../Stack/ArrayStack.h"
#include "../Queue/Queue.h"
#include "../Queue/CircularQueue.h"
#include <iostream>
#include <string>
using namespace std;
string reverseWithStack(const string& s) {
    Stack st;
    string result;
    for (char c : s) st.push(static_cast<unsigned char>(c));
    int v;
    while (st.pop(v)) result += static_cast<char>(v);
    return result;
}
bool isPalindrome(const string& s) { return s == reverseWithStack(s); }
bool isBalanced(const string& s) {
    Stack st;
    for (char c : s) {
        if (c=='(' || c=='[' || c=='{') st.push(c);
        else if (c==')' || c==']' || c=='}') {
            int v;
            if (!st.pop(v)) return false;
            if ((c==')' && v!='(') || (c==']' && v!='[') || (c=='}' && v!='{')) return false;
        }
    }
    return st.isEmpty();
}
class TwoStackQueue {
    Stack inbox, outbox;
public:
    void enqueue(int value) { inbox.push(value); }
    bool dequeue(int& value) {
        if (outbox.isEmpty()) {
            int v;
            while (inbox.pop(v)) outbox.push(v);
        }
        return outbox.pop(value);
    }
    bool isEmpty() const { return inbox.isEmpty() && outbox.isEmpty(); }
};
class Editor {
    string text;
    Stack undoStack, redoStack;
public:
    void type(char c) {
        text += c;
        undoStack.push(static_cast<unsigned char>(c));
        redoStack.clear();
    }
    bool undo() {
        int v;
        if (!undoStack.pop(v)) return false;
        text.pop_back();
        redoStack.push(v);
        return true;
    }
    bool redo() {
        int v;
        if (!redoStack.pop(v)) return false;
        text += static_cast<char>(v);
        undoStack.push(v);
        return true;
    }
    string getText() const { return text; }
};
void runWeek04() {
    cout << "--- Week 4: Stacks and Queues ---" << endl << boolalpha;
    int v=0;
    Stack s;
    s.push(2); s.push(7); s.push(5); s.push(8);
    cout << "[Q2] "; s.display();
    s.pop(v); cout << "[Q2] pop -> " << v << endl;
    s.push(4); cout << "[Q2] "; s.display();
    s.peek(v); cout << "[Q2] peek -> " << v << " size = " << s.size() << endl;
    while(s.pop(v)) cout << "[Q2] pop -> " << v << endl;
    cout << "[Q2] pop on empty = " << s.pop(v) << endl;
    ArrayStack as;
    for (int i=1;i<=6;i++) cout << "[Q3] push(" << i*10 << ") = " << as.push(i*10) << endl;
    cout << "[Q3] "; as.display();
    cout << "[Q3] isFull = " << as.isFull() << " size = " << as.size() << endl;
    as.pop(v); cout << "[Q3] pop -> " << v << " push(60) = " << as.push(60) << endl;
    cout << "[Q3] "; as.display();
    cout << "[Q4] " << reverseWithStack("CENG203") << endl;
    cout << "[Q4] " << reverseWithStack("stack") << endl;
    cout << "[Q4 bonus] level = " << isPalindrome("level") << ", stack = " << isPalindrome("stack") << endl;
    Queue q;
    q.enqueue(2);q.enqueue(7);q.enqueue(5);q.enqueue(8);
    cout << "[Q5] ";q.display();
    q.dequeue(v);cout << "[Q5] dequeue -> " << v << endl;
    q.enqueue(4);cout << "[Q5] ";q.display();
    q.peek(v);cout << "[Q5] peek -> " << v << " size = " << q.size() << endl;
    while(q.dequeue(v))cout << "[Q5] dequeue -> " << v << endl;
    cout << "[Q5] dequeue on empty = " << q.dequeue(v) << endl;
    q.enqueue(9);cout << "[Q5] ";q.display();
    string tests[]={"([]{})","{[()()]}","([)]","((",")(",""};
    for(const string& t:tests)cout << "[Q6] \"" << t << "\" -> " << isBalanced(t) << endl;
    CircularQueue cq;
    for(int i=1;i<=6;i++)cout << "[Q7] enqueue(" << i << ") = " << cq.enqueue(i) << endl;
    cout << "[Q7] ";cq.display();
    cq.dequeue(v);cout << "[Q7] dequeue -> " << v << endl;
    cq.dequeue(v);cout << "[Q7] dequeue -> " << v << endl;
    cout << "[Q7] enqueue(6) = " << cq.enqueue(6) << " enqueue(7) = " << cq.enqueue(7) << endl;
    cout << "[Q7] ";cq.display();
    TwoStackQueue tq;
    tq.enqueue(1);tq.enqueue(2);tq.enqueue(3);
    tq.dequeue(v);cout << "[Q8] dequeue -> " << v << endl;
    tq.enqueue(4);
    while(tq.dequeue(v))cout << "[Q8] dequeue -> " << v << endl;
    cout << "[Q8] isEmpty = " << tq.isEmpty() << endl;
    Editor ed;
    ed.type('a');ed.type('b');ed.type('c');
    cout << "[Q9] typed abc -> \"" << ed.getText() << "\"" << endl;
    ed.undo();ed.undo();cout << "[Q9] undo, undo -> \"" << ed.getText() << "\"" << endl;
    ed.redo();cout << "[Q9] redo -> \"" << ed.getText() << "\"" << endl;
    ed.type('x');cout << "[Q9] type x -> \"" << ed.getText() << "\"" << endl;
    cout << "[Q9] redo after type = " << ed.redo() << endl;
}
