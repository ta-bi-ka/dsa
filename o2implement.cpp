#include <bits/stdc++.h>
using namespace std;

/* ------------ ArrayStack ------------ */
class ArrayStack {
    int *arr;
    int capacity;
    int topIndex;

public:
    ArrayStack(int cap = 1000) {
        capacity = cap;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(int x) {
        if (topIndex + 1 == capacity) {
            cout << "ArrayStack Overflow!\n";
            return;
        }
        arr[++topIndex] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "ArrayStack Underflow!\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top() {
        if (isEmpty()) {
            cout << "ArrayStack Empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

/* ------------ ListStack ------------ */
class ListStack {
    struct Node {
        int data;
        Node *next;
        Node(int d) {
            data = d;
            next = nullptr;
        }
    };

    Node *head;
    int sz;

public:
    ListStack() {
        head = nullptr;
        sz = 0;
    }

    ~ListStack() {
        while (!isEmpty()) pop();
    }

    void push(int x) {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        sz++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "ListStack Underflow!\n";
            return -1;
        }
        Node *temp = head;
        int val = head->data;
        head = head->next;
        delete temp;
        sz--;
        return val;
    }

    int top() {
        if (isEmpty()) {
            cout << "ListStack Empty!\n";
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return sz;
    }
};

/* ------------ MyQueue using two stacks ------------ */
class MyQueue {
    ArrayStack inStack;   // enqueue happens here
    ListStack outStack;   // dequeue happens here

    void transferIfNeeded() {
        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }
    }

public:
    MyQueue(int cap = 1000) : inStack(cap) {}

    void enqueue(int x) {
        inStack.push(x);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        transferIfNeeded();
        return outStack.pop();
    }

    int front() { // peek
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        transferIfNeeded();
        return outStack.top();
    }

    bool isEmpty() {
        return inStack.isEmpty() && outStack.isEmpty();
    }

    int size() {
        return inStack.size() + outStack.size();
    }
};

/* ------------ Testing ------------ */
int main() {
    MyQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << "\n"; // 10
    cout << q.dequeue() << "\n"; // 20

    q.enqueue(40);

    cout << q.front() << "\n";   // 30
    cout << q.dequeue() << "\n"; // 30
    cout << q.dequeue() << "\n"; // 40

    return 0;
}
