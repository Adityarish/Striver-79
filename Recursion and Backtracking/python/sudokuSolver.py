# Problem Statement:
# Given a 9x9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.
#          1. All the rows should be filled with numbers(1 - 9) exactly once.
#          2. All the columns should be filled with numbers(1 - 9) exactly once.
#          3. Each 3x3 submatrix should be filled with numbers(1 - 9) exactly once.
# Note: Character '.' indicates empty cell.

# Problem Link: https://www.codingninjas.com/studio/problems/sudoku-solver_8416969?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def is_safe(row, col, board, val):
    for i in range(len(board)):
        # Check row-wise
        if board[row][i] == val:
            return False
        # Check column-wise
        if board[i][col] == val:
            return False
        # Check subgrid (3x3)
        if board[3 * (row // 3) + (i // 3)][3 * (col // 3) + (i % 3)] == val:
            return False
    return True

def solve(board):
    n = len(board[0])
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:
                for val in range(1, 10):
                    if is_safe(i, j, board, val):
                        board[i][j] = val
                        
                        next_solution_possible = solve(board)
                        if next_solution_possible:
                            return True
                        else:
                            board[i][j] = 0
                            
                return False
    return True

def sudoku_solver(board):
    return solve(board)
