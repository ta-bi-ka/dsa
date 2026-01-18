#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> A, B, C;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "enter") {
            int id;
            cin >> id;

            if ((int)B.size() <= (int)C.size()) {
                B.push(id);
                cout << "Customer " << id << " enters queue B\n";
            } else {
                C.push(id);
                cout << "Customer " << id << " enters queue C\n";
            }
        }
        else if (cmd == "A") {
            string action;
            cin >> action; // approve

            if (A.empty()) {
                cout << "Queue A was already empty\n";
            } else {
                int id = A.front(); A.pop();
                cout << "Customer " << id << " gets the loan\n";
            }
        }
        else if (cmd == "B" || cmd == "C") {
            string action;
            cin >> action;

            queue<int> &Q = (cmd == "B") ? B : C;

            if (Q.empty()) {
                cout << "Queue " << cmd << " was already empty\n";
                continue;
            }

            int id = Q.front(); Q.pop();

            if (action == "approve") {
                A.push(id);
                cout << "Customer " << id << " enters queue A\n";
            }
            else if (action == "reject") {
                // re-enter larger of B and C
                if ((int)B.size() >= (int)C.size()) {
                    B.push(id);
                    cout << "Customer " << id << " re-enters queue B\n";
                } else {
                    C.push(id);
                    cout << "Customer " << id << " re-enters queue C\n";
                }
            }
        }
    }
    return 0;
}
