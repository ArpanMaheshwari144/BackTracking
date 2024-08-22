/*
Question Link -> https://www.geeksforgeeks.org/problems/n-queen-problem0315/1
Question -> Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Examples :

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
*/

#include <bits/stdc++.h>
using namespace std;

bool canNumberPlaced(char num, int rowIndex, int colIndex, vector<vector<char>> &board)
{
    // for checking row
    for (int j = 0; j < 9; j++)
    {
        // agar wo num phle se hi waha hai to return false kardo
        if (board[rowIndex][j] == num)
        {
            return false;
        }
    }

    // for checking col
    for (int i = 0; i < 9; i++)
    {
        if (board[i][colIndex] == num)
        {
            return false;
        }
    }

    int subRowGrid = (rowIndex / 3) * 3;
    int subColGrid = (colIndex / 3) * 3;
    for (int i = subRowGrid; i < subRowGrid + 3; i++)
    {
        for (int j = subColGrid; j < subColGrid + 3; j++)
        {
            if (board[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int rowIndex, int colIndex, vector<vector<char>> &board)
{
    // base case
    if (rowIndex == 9)
    {
        return true;
    }

    if (colIndex == 9)
    {
        return solve(rowIndex + 1, 0, board);
    }

    // pre-filled cell
    if (board[rowIndex][colIndex] != '.')
    {
        return solve(rowIndex, colIndex + 1, board);
    }

    // for filling 1 to 9 options in the sudoku
    for (char num = '1'; num <= '9'; num++)
    {
        if (canNumberPlaced(num, rowIndex, colIndex, board))
        {
            board[rowIndex][colIndex] = num;
            // conditional backtracking
            if (solve(rowIndex, colIndex + 1, board))
            {
                return true;
            }
            board[rowIndex][colIndex] = '.'; // backtrack
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(0, 0, board);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}