#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited){
    int m=grid.size();
    int n=grid[0].size();
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0' || visited[i][j]){
        return;
    }
    visited[i][j]=true;
    DFS(grid,i+1,j,visited);
    DFS(grid,i-1,j,visited);
    DFS(grid,i,j+1,visited);
    DFS(grid,i,j-1,visited);
}

int numIslands(vector<vector<char>> &grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                count++;
                DFS(grid,i,j,visited);
            }
        }
    }
    return count;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>> grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<numIslands(grid)<<endl;
    return 0;
}
