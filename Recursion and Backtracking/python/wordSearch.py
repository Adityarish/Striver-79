# Problem Statement: Given an m x n grid of characters board and a string word, return true if the word exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

# Problem Link: https://www.codingninjas.com/studio/problems/word-search---l_892986?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def backtrack(board, target_word, i, j, k):
    n = len(board)
    m = len(board[0])
    
    if k == len(target_word):
        return True
        
    if i < 0 or i >= n or j < 0 or j >= m or board[i][j] != target_word[k]:
        return False
        
    temp = board[i][j]
    board[i][j] = ' '
    
    found = (backtrack(board, target_word, i + 1, j, k + 1) or
             backtrack(board, target_word, i - 1, j, k + 1) or
             backtrack(board, target_word, i, j + 1, k + 1) or
             backtrack(board, target_word, i, j - 1, k + 1))
             
    board[i][j] = temp
    
    return found

def present(board, word, n, m):
    for i in range(n):
        for j in range(m):
            if board[i][j] == word[0] and backtrack(board, word, i, j, 0):
                return True
                
    return False
