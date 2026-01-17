#include <bits\stdc++.h>

using namespace std;

void helper(vector<vector<int>> &maze, int row, int col, vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    int n = maze.size();

    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || visited[row][col])
    {

        return;
    }
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[row][col] = true;
    // Down

    helper(maze, row + 1, col, ans, visited, path + 'D');

    // Left

    helper(maze, row, col - 1, ans, visited, path + 'L');

    // Right

    helper(maze, row, col + 1, ans, visited, path + 'R');

    // Up

    helper(maze, row - 1, col, ans, visited, path + 'U');
}

vector<string> findPath(vector<vector<int>> &maze)
{
    vector<string> ans;

    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";

    helper(maze, 0, 0, ans, visited, path);

    return ans;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<string> paths = findPath(maze);

    for (const string &path : paths)
    {
        cout << path << endl;
    }

    return 0;
}
