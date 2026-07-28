# Problem Statement: You are given an array/list 'ARR' consisting of 'N' non-negative integers. You are also given a list 'QUERIES' consisting of 'M' queries, where the 'i-th' query is a list/array of two non-negative integers 'Xi', 'Ai', i.e 'QUERIES[i]' = ['Xi', 'Ai'].
# The answer to the ith query, i.e 'QUERIES[i]' is the maximum bitwise xor value of 'Xi' with any integer less than or equal to 'Ai' in 'ARR'. You should return an array/list consisting of 'N' integers where the 'i-th' integer is the answer of 'QUERIES[i]'.

# Problem Link: https://www.codingninjas.com/studio/problems/maximum-xor-with-an-element-from-array_1382020?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class Node:
    def __init__(self):
        self.links = [None, None]

    def contains_key(self, key):
        return self.links[key] is not None

    def get(self, key):
        return self.links[key]

    def put(self, key, node):
        self.links[key] = node

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, num):
        node = self.root
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if not node.contains_key(bit):
                node.put(bit, Node())
            node = node.get(bit)

    def get_xor(self, num):
        node = self.root
        max_val = 0
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if node.contains_key(1 - bit):
                max_val |= (1 << i)
                node = node.get(1 - bit)
            else:
                node = node.get(bit)
        return max_val

def max_xor_queries(arr, queries):
    arr.sort()
    m = len(queries)
    offline_queries = [[q[1], q[0], i] for i, q in enumerate(queries)]
    offline_queries.sort()

    ind = 0
    n = len(arr)
    trie = Trie()
    ans = [-1] * m

    for i in range(m):
        while ind < n and arr[ind] <= offline_queries[i][0]:
            trie.insert(arr[ind])
            ind += 1
        query_ind = offline_queries[i][2]
        if ind != 0:
            ans[query_ind] = trie.get_xor(offline_queries[i][1])
        else:
            ans[query_ind] = -1

    return ans
