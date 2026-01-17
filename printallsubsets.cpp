#include<bits/stdc++.h>

using namespace std;

void printAllSubsetsUtil(const vector<int> &set, int index, vector<int> &current, vector<vector<int>> &result) {
    if (index == set.size()) {
        result.push_back(current);
        return;
    }
    // Include the current element
    current.push_back(set[index]);
    printAllSubsetsUtil(set, index + 1, current, result);
    // Exclude the current element
    current.pop_back();
    printAllSubsetsUtil(set, index + 1, current, result);
}

vector<vector<int>> printAllSubsets(const vector<int> &set) {
    vector<vector<int>> result;
    vector<int> current;
    printAllSubsetsUtil(set, 0, current, result);
    return result;
}

int main() {
    vector<int> set;

    // take input
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        set.push_back(x);
    }

    vector<vector<int>> subsets = printAllSubsets(set);
    
    for (const auto &subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}












