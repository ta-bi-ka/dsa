#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;
    
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        
        // Skip spaces
        if (ch == ' ') {
            continue;
        }
        
        // If digit, push to stack
        if (isdigit(ch)) {
            s.push(ch - '0');  // Convert char to int
        }
        // If operator, pop two operands and apply operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            int result;
            
            if (ch == '+') {
                result = operand1 + operand2;
            } else if (ch == '-') {
                result = operand1 - operand2;
            } else if (ch == '*') {
                result = operand1 * operand2;
            } else if (ch == '/') {
                result = operand1 / operand2;
            }
            
            s.push(result);
        }
    }
    
    // Final result is the only element left in stack
    int result = s.top();
    s.pop();
    return result;
}