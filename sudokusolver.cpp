#include <bits\stdc++.h>
using namespace std;

bool helper(vector<vector<char>> &board, int row, int col)
{
 if (row == 9)
    {
        return true;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9)
    {  
        nextRow = row + 1;
        nextCol = 0;
    }
    if (board[row][col] != '.')
        return (helper(board, nextRow, nextCol));

    for (char digit = '1'; digit <= '9'; digit++)
    {
        if (isSafe(board, row, col, digit))
        {
            board[row][col] = digit;
        return (helper(board, nextRow, nextCol));

        }
        board[row][col] = '.';
    }
    return false;
}

bool isSafe(vector<vector<char>> &board, int row, int col, int digit)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == digit)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == digit)
        {
            return false;
        }
    }


    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i <= startRow + 2; i++)
    {
        for (int j = 0; j <= startCol + 2; j++)
        {
            if (board[i][j] == digit)
            {
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    helper(board, 0, 0);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (const auto &row : board)
    {
        for (const auto &ch : row)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}