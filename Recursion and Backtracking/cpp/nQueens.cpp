// Problem Statement: The n-queens is the problem of placing n queens on n x n chessboard such that no two queens can attack each other. 
// Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen's placement, where 'Q' and '.' indicate queen and empty space respectively.

// Problem Link: https://www.codingninjas.com/studio/problems/n-queens_696453?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
using namespace std;

vector<int> construct(vector<vector<int>>& board) {
    vector<int> res;
    for (const auto& row : board) {
        for (int element : row) {
            res.push_back(element);
        }
    }
    return res;
}

void solve(int col, vector<vector<int>>& board, vector<vector<int>>& ans, 
           vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
    if (col == n) {
        ans.push_back(construct(board));
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 1;
            leftRow[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[n - 1 + col - row] = 1;

            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

            board[row][col] = 0;
            leftRow[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    vector<int> leftRow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);

    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}
