#include<bits\stdc++.h>
using namespace std;

class MinStack {
    stack<long long int> s;
    long long int minElement;   
public:
    MinStack() {
       
    }

    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minElement = x;
        } else {
            if (x <minElement) {
                s.push((long long int)2*x - minElement);
                minElement = x;
            } else {
                s.push(x);
            }
        }
    }

    void pop() {
       if(s.top() < minElement) {
           minElement = 2*minElement - s.top();
       }
         s.pop();
    }

    int top() {
       if(s.top() < minElement) {
           return minElement;
       } else {
           return s.top();
       }
    }

    int getMin() {
        if (s.empty()) throw runtime_error("Stack is empty");
        return minElement;
    }
};  



class Minstack
{
    stack<pair<int,int>> s;
public:
    void push(int x) {
        if (s.empty()) {
            s.push({x, x});
        } else {
            int currentMin = s.top().second;
            s.push({x, min(x, currentMin)});
        }
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }
    int top() {
        if (s.empty()) throw runtime_error("Stack is empty");
        return s.top().first;
    }
    int getMin() {
        if (s.empty()) throw runtime_error("Stack is empty");
        return s.top().second;
    }
};