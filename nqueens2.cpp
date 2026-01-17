#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n) {
    // Check this column on upper side
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solveNQueensUtil(vector<string> &board, int row, int n, vector<vector<string>> &solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q'; // Place queen
            solveNQueensUtil(board, row + 1, n, solutions);
            board[row][col] = '.'; // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solveNQueensUtil(board, 0, n, solutions);
    return solutions;
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> solutions = solveNQueens(n);

    for (const auto &solution : solutions) {
        for (const auto &row : solution) {
            cout << row << endl;
        }
        cout << endl; // Separate different solutions
    }

    return 0;
}

