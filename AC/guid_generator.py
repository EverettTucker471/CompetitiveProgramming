import sys
sys.setrecursionlimit(10 ** 4)

n = int(input())
s = input()
s = [int(x) + 1 if x.isdigit() else (ord(x) - ord('a') + 11) for x in s]

MOD = (10 ** 9 + 7) * (10 ** 9 + 9)
r = 31

adj = [[] for i in range(n)]
for i in range(n - 1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

ans = set()
def dfs(node, hash):
    ans.add(hash)
    visited[node] = True
    for v in adj[node]:
        if not visited[v]:
            newHash = (r * hash + s[v]) % MOD
            dfs(v, newHash)

for i in range(n):
    visited = [False] * n
    dfs(i, s[i])

print(len(ans))