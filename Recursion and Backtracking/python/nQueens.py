# Problem Statement: The n-queens is the problem of placing n queens on n x n chessboard such that no two queens can attack each other. 
# Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen's placement, where 'Q' and '.' indicate queen and empty space respectively.

# Problem Link: https://www.codingninjas.com/studio/problems/n-queens_696453?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def construct(board):
    res = []
    for row in board:
        for element in row:
            res.append(element)
    return res

def solve(col, board, ans, left_row, upper_diagonal, lower_diagonal, n):
    if col == n:
        ans.append(construct(board))
        return

    for row in range(n):
        if left_row[row] == 0 and upper_diagonal[row + col] == 0 and lower_diagonal[n - 1 + col - row] == 0:
            board[row][col] = 1
            left_row[row] = 1
            upper_diagonal[row + col] = 1
            lower_diagonal[n - 1 + col - row] = 1

            solve(col + 1, board, ans, left_row, upper_diagonal, lower_diagonal, n)

            board[row][col] = 0
            left_row[row] = 0
            upper_diagonal[row + col] = 0
            lower_diagonal[n - 1 + col - row] = 0

def n_queens(n):
    board = [[0] * n for _ in range(n)]
    ans = []
    left_row = [0] * n
    upper_diagonal = [0] * (2 * n - 1)
    lower_diagonal = [0] * (2 * n - 1)

    solve(0, board, ans, left_row, upper_diagonal, lower_diagonal, n)
    return ans
