#include<bits/stdc++.h>
using namespace std;

bool areParenthesesBalanced(const string& expr) {
    stack<char> s;

    for(char ch : expr) {
        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(s.empty()) return false;

            if(s.top() == '(' && ch == ')') s.pop();
            else if(s.top() == '{' && ch == '}') s.pop();
            else if(s.top() == '[' && ch == ']') s.pop();
            else return false;
        }
    }

    return s.empty();
}
