#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(queue<char> &q) {
    int n = q.size();
    stack<char> st;

    // Step 1: copy queue elements into stack (preserve queue order)
    for (int i = 0; i < n; i++) {
        char x = q.front();
        q.pop();

        st.push(x);
        q.push(x); // restore by rotation
    }

    bool ok = true;

    // Step 2: compare and again preserve queue
    for (int i = 0; i < n; i++) {
        char x = q.front();
        q.pop();

        if (x != st.top()) ok = false;
        st.pop();

        q.push(x); // restore queue
    }

    return ok;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        queue<char> q;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            q.push(c);
        }

        cout << (isPalindrome(q) ? "True" : "False") << "\n";
    }

    return 0;
}
