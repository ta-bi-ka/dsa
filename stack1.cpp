#include<bits\stdc++.h>
using namespace std;
class Stack {
    vector<int> elements;

public:
    void push(int x) {
        elements.push_back(x);
    }   
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }
    int top() {
        if (!elements.empty()) {
            return elements.back();
        }
        throw runtime_error("Stack is empty");
    }
    bool isEmpty() {
        return elements.empty();
    }
    int size() {
        return elements.size();
    }
    void display() {
        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};
int main() {    
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
    cout << "Stack elements: ";
    s.display();
    s.pop();
    cout << "After popping, top element: " << s.top() << endl;
    return 0;
}
