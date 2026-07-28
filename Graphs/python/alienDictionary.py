# Problem Statement: Given a sorted dictionary of an alien language having N words and k starting alphabets of a standard dictionary. Find the order of characters in the alien language.
# Note: Many orders may be possible for a particular test case, thus you may return any valid order.

# Problem Link: https://www.codingninjas.com/studio/problems/alien-dictionary_630423?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def dfs(node, vis, adj, st):
    vis[node] = True
    for it in adj[node]:
        if not vis[it]:
            dfs(it, vis, adj, st)
    st.append(node)

def get_alien_language(dictionary, k):
    adj = [[] for _ in range(k)]
    for i in range(len(dictionary) - 1):
        s1 = dictionary[i]
        s2 = dictionary[i + 1]
        length = min(len(s1), len(s2))
        for ptr in range(length):
            if s1[ptr] != s2[ptr]:
                adj[ord(s1[ptr]) - ord('a')].append(ord(s2[ptr]) - ord('a'))
                break
                
    vis = [False] * k
    st = []
    
    for i in range(k):
        if not vis[i]:
            dfs(i, vis, adj, st)
            
    ans = ""
    while st:
        ans += chr(st[-1] + ord('a'))
        st.pop()
        
    return ans
