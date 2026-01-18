

#include<bits\stdc++.h>
using namespace std;




int firstUniqueChar(const string& s) {
    unordered_map<char, int> charCount;
    queue<int> charQueue;

    for(int i = 0; i < s.size(); i++) {
        if(charCount.find(s[i]) == charCount.end()) {
            charQueue.push(i);
        }

        charCount[s[i]]++;

        while(!charQueue.empty() && charCount[s[charQueue.front()]] > 1) {
            charQueue.pop();
        }
    }

    return charQueue.empty() ? -1 : charQueue.front();
}
