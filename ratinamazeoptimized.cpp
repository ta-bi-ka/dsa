#include<bits\stdc++.h>

using namespace std;

void helper(vector<vector<int>> &maze, int row, int col, vector<string> &ans, string path)
{
    int n = maze.size();

    if (row<0 || col<0 || row>=n || col>=n || maze[row][col] == 0|| maze[row][col] == -1) {

        return;
    }
  if(row == n - 1 && col == n - 1)
  {
        ans.push_back(path);
        return; 
  }



  maze[row][col] = -1;
    // Down
        helper(maze, row + 1, col, ans, path + 'D');
    

    // Left

        helper(maze, row, col - 1, ans, path + 'L');
    

    // Right
        helper(maze, row, col + 1, ans, path + 'R');
    

    // Up
        helper(maze, row - 1, col, ans, path + 'U');
    

    maze[row][col] = 1;
}


vector<string> findPath(vector<vector<int>> &maze) {
    vector<string> ans;

    int n= maze.size();
    string path = "";

    helper(maze, 0, 0, ans,path);

    return ans;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findPath(maze);

    for (const string &path : paths) {
        cout << path << endl;
    }

    return 0;
}


