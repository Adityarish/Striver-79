# Problem Statement: Given a list of accounts where each element account [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
# Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
# After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.

# Note: Accounts themselves can be returned in any order.

# Problem Link: https://www.codingninjas.com/studio/problems/accounts-merge_1089558?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

from collections import defaultdict

class DisjointSet:
    def __init__(self, n):
        self.rank = [0] * n
        self.parent = list(range(n))
        
    def find_parent(self, node):
        if node == self.parent[node]:
            return node
        self.parent[node] = self.find_parent(self.parent[node])
        return self.parent[node]
        
    def union_by_rank(self, u, v):
        pu = self.find_parent(u)
        pv = self.find_parent(v)
        
        if pu == pv:
            return
            
        if self.rank[pu] < self.rank[pv]:
            self.parent[pu] = pv
        elif self.rank[pu] > self.rank[pv]:
            self.parent[pv] = pu
        else:
            self.parent[pv] = pu
            self.rank[pu] += 1

def accounts_merge(accounts):
    n = len(accounts)
    ds = DisjointSet(n)
    
    email_to_index = {}
    
    for i in range(n):
        for j in range(1, len(accounts[i])):
            email = accounts[i][j]
            if email not in email_to_index:
                email_to_index[email] = i
            else:
                ds.union_by_rank(i, email_to_index[email])
                
    merged_emails = defaultdict(list)
    
    for email, idx in email_to_index.items():
        node = ds.find_parent(idx)
        merged_emails[node].append(email)
        
    result = []
    
    for i in range(n):
        if i in merged_emails:
            merged_list = sorted(merged_emails[i])
            merged_list.insert(0, accounts[i][0])
            result.append(merged_list)
            
    return result
