#include<bits\stdc++.h>
using namespace std;


int main() {    
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < prices.size(); i++) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans.push_back(i + 1);
        } else {
            ans.push_back(i - s.top());
        }
        s.push(i);
    }
    for (int span : ans) {
        cout << span << " ";
    }



    return 0;
}




































#include<bits\stdc++.h>
using namespace std;
int main() {    
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < prices.size(); i++) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans.push_back(i + 1);
        } else {
            ans.push_back(i - s.top());
        }
        s.push(i);
    }
    for (int span : ans) {
        cout << span << " ";
    }   
    return 0;
}