#include <bits/stdc++.h>
using namespace std;

/* ---------------- Queue ADT ---------------- */
class Queue {
    list<int> L;

public:
    void enqueue(int x) {
        L.push_back(x);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int x = L.front();
        L.pop_front();
        return x;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return -1;
        }
        return L.front();
    }

    bool isEmpty() {
        return L.empty();
    }

    int size() {
        return (int)L.size();
    }

    void print() {
        for (int x : L) cout << x << " ";
        cout << "\n";
    }
};

/* ---------------- isPalindrome function ---------------- */
bool isPalindrome(Queue *q) {
    int n = q->size();
    stack<int> st;

    // Step 1: Copy all elements to stack (preserve queue)
    for (int i = 0; i < n; i++) {
        int x = q->dequeue();
        st.push(x);
        q->enqueue(x);
    }

    bool ok = true;

    // Step 2: Compare queue with stack while restoring queue
    for (int i = 0; i < n; i++) {
        int x = q->dequeue();

        if (x != st.top()) ok = false;
        st.pop();

        q->enqueue(x);
    }

    return ok;
}

/* ---------------- Main Function ---------------- */
int main() {
    Queue q;

    // Example 1: Palindrome
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);

    cout << "Queue: ";
    q.print();

    cout << (isPalindrome(&q) ? "Palindrome\n" : "Not Palindrome\n");

    cout << "Queue after function: ";
    q.print(); // must remain same

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(queue<int> &q) {
    int n = q.size();
    stack<int> st;

    // Step 1: Put all elements into stack while keeping queue same
    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();

        st.push(x);
        q.push(x);   // restore order by rotation
    }

    bool ok = true;

    // Step 2: Compare stack top with queue front (restore queue again)
    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();

        if (x != st.top()) ok = false;
        st.pop();

        q.push(x);   // restore queue
    }

    return ok;
}

int main() {
    queue<int> q;

    // Example: 1 2 3 2 1
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(2);
    q.push(1);

    cout << (isPalindrome(q) ? "Palindrome\n" : "Not Palindrome\n");

    // Check queue preserved
    cout << "Queue after function: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}
