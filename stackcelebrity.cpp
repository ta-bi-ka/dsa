#include<bits\stdc++.h>
using namespace std;

int getCelebrity(int n, vector<vector<int>>& knows) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();

        if (knows[a][b] == 1) {
            s.push(b);
        } else {
            s.push(a);
        }
    }

    int candidate = s.top();

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows[candidate][i] == 1 || knows[i][candidate] == 0) {
                return -1;
            }
        }
    }

    return candidate;
}


int main() {
    int n = 4;
    vector<vector<int>> knows = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    int celebrity = getCelebrity(n, knows);
    if (celebrity != -1) {
        cout << "The celebrity is person " << celebrity << endl;
    } else {
        cout << "There is no celebrity in the group." << endl;
    }

    return 0;
}
