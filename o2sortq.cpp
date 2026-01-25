#include <bits/stdc++.h>
using namespace std;

void sortQueue(queue<int> &q) {
    int n = q.size();
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int unsorted = n - i;

        // Step 1: find maximum in first "unsorted" elements
        int mx = INT_MIN;
        for (int j = 0; j < unsorted; j++) {
            int x = q.front(); q.pop();
            mx = max(mx, x);
            q.push(x);
        }

        // Step 2: remove FIRST occurrence of mx from first "unsorted"
        bool removed = false;
        for (int j = 0; j < unsorted; j++) {
            int x = q.front(); q.pop();

            if (!removed && x == mx) {
                st.push(x);      // store max in stack
                removed = true;  // remove only one mx
            } else {
                q.push(x);
            }
        }

        // Step 3: rotate remaining (sorted part) elements back
        // (the last i elements are already rotated behind)
        // for (int j = 0; j < i; j++) {
        //     q.push(q.front());
        //     q.pop();
        // }
    }

    // Now stack has elements such that popping gives increasing order
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        queue<int> q;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            q.push(x);
        }

        sortQueue(q);

        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }
    return 0;
}
