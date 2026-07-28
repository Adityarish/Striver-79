# Problem Statement: Given a string, find all the possible subsequences of the string.

# Problem Link: https://www.codingninjas.com/studio/problems/print-subsequences_8416366?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def generate_subsequences(s):
    if len(s) == 0:
        return [""]
        
    ch = s[0]
    ss = s[1:]
    
    sa = generate_subsequences(ss)
    res = []
    
    for string in sa:
        res.append(string)
        res.append(ch + string)
        
    return res
