/*
Question Link -> https://www.geeksforgeeks.org/problems/n-queen-problem0315/1
Question -> The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number.

Examples :

Input: 1
Output: [1]
Explaination: Only one queen can be placed
in the single cell available.
Input: 4
Output: [2 4 1 3 ] [3 1 4 2 ]
Explaination: These are the 2 possible solutions.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
bool check(int rowIndex, int colIndex, int n, vector<vector<int>> &board)
{
    // check row
    for (int col = 0; col < colIndex; col++)
    {
        if (board[rowIndex][col] == 1)
        {
            return false;
        }
    }

    // check diagonal(top-left diagonal)
    /*
    We only need to check the left diagonals because we are placing the queens from left to right, making it unnecessary to check the right side.
                    (i-1, 0)
    (i-1, j-1)      j ->     (i-1, j+1)
                    |
                    |
                    |
                    |
                    |
(0, j-1)i___________|___________(0, j+1)
        ↓           |
                    |
                    |
                    |
                    |
    (i+1, j-1)      |        (i+1, j+1)
                    (i+1, 0)
    */
    int i = rowIndex, j = colIndex;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    // check diagonal(bottom-left diagonal)
    i = rowIndex, j = colIndex;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(int colIndex, vector<vector<int>> &board, int n, vector<int> &temp)
{
    if (colIndex == n)
    {
        ans.push_back(temp);
        return;
    }

    // column wise traversal
    // for all column index, trying all row index
    for (int rowIndex = 0; rowIndex < n; rowIndex++)
    {
        // is safe to place
        if (check(rowIndex, colIndex, n, board))
        {
            temp.push_back(rowIndex + 1);
            board[rowIndex][colIndex] = 1;
            solve(colIndex + 1, board, n, temp);
            // backtrack
            temp.pop_back();
            board[rowIndex][colIndex] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> temp;
    solve(0, board, n, temp);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> ans = nQueen(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }

    return 0;
}