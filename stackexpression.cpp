#include <bits/stdc++.h>
using namespace std;

bool isOperator(const string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<long long> st;

    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;

        if (!isOperator(token)) {
            // number
            st.push(stoll(token));
        } else {
            // operator
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();

            long long res = 0;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") res = a / b; // integer division

            st.push(res);
        }
    }

    cout << st.top() << "\n";
    return 0;
}
