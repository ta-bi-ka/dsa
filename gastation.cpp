#include<bits\stdc++.h>
using namespace std;
int cancompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
    int totalGas = 0, totalCost = 0;
    int currentGas = 0, startingStation = 0;

    for(int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        currentGas += gas[i] - cost[i];

        if(currentGas < 0) {
            startingStation = i + 1;
            currentGas = 0;
        }
    }

    return totalGas < totalCost ? -1 : startingStation;
}