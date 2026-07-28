// Problem Statement:
// Given a 9x9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.
//          1. All the rows should be filled with numbers(1 - 9) exactly once.
//          2. All the columns should be filled with numbers(1 - 9) exactly once.
//          3. Each 3x3 submatrix should be filled with numbers(1 - 9) exactly once.
// Note: Character '.' indicates empty cell.

// Problem Link: https://www.codingninjas.com/studio/problems/sudoku-solver_8416969?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
    for (int i = 0; i < board.size(); i++) {
        // Check row-wise
        if (board[row][i] == val) {
            return false;
        }
        // Check column-wise
        if (board[i][col] == val) {
            return false;
        }
        // Check subgrid (3x3)
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board) {
    int n = board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) { // Find an empty cell
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(i, j, board, val)) {
                        board[i][j] = val; // Place 'val'
                        
                        // Recursively solve for the next cell
                        bool nextSolutionPossible = solve(board);
                        if (nextSolutionPossible) {
                            return true; // If a valid solution is found
                        } else {
                            board[i][j] = 0; // Backtrack and reset the cell
                        }
                    }
                }
                return false; // No valid value can be placed
            }
        }
    }
    return true; // Puzzle is solved
}

bool sudokuSolver(vector<vector<int>>& board) {
    return solve(board);
}
