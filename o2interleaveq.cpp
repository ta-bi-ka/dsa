#include <bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    int half = n / 2;

    queue<int> q2; // only one extra queue

    // Step 1: move first half into q2
    for (int i = 0; i < half; i++) {
        q2.push(q.front());
        q.pop();
    }

    // Step 2: interleave back into q
    while (!q2.empty()) {
        // take from first half
        q.push(q2.front());
        q2.pop();

        // take from second half (currently at front of q)
        q.push(q.front());
        q.pop();
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
            int x;
            cin >> x;
            q.push(x);
        }

        interleaveQueue(q);

        // print result
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }

    return 0;
}
