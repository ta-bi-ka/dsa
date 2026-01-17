#include<bits\stdc++.h>
using namespace std;    

bool isPalin(const string &s){
   string s2=s;
   reverse(s2.begin(),s2.end());

    return s == s2;
}

void getAllPalindromePartitions(const string &s, vector<string> &partitions, vector<vector<string>> &result) {
    if (s.empty()) {
        result.push_back(partitions);
        return;
    }

    for (int len = 0; len <s.size(); ++len) {
        string prefix = s.substr(0, len+1);
        
       if(isPalin(prefix)){
           partitions.push_back(prefix);
           getAllPalindromePartitions(s.substr(len+1), partitions, result);
           partitions.pop_back();
       }
    }
}

vector<vector<string>> palindromePairs(string s) {
    vector<vector<string>> result;
    vector<string> partitions;

    getAllPalindromePartitions(s,partitions,result);
    
    return result;
}


int main(){
    string s="aab";
    vector<vector<string>> ans=palindromePairs(s);

    for(auto &partition:ans){
        for(auto &str:partition){
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}