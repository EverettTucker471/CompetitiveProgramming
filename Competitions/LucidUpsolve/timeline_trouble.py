from collections import deque


n, m = map(int, input().strip().split())

req = [0] * n
for i in range(m):
    a, b = map(int, input().strip().split())
    req[b] += 1 << a

# Construct the lookup table from the constraints
def possible(state):
    # If it's possible to visit event i from the binary state

    rtn = [True] * n
    temp = state
    for i in range(n):
        if temp % 2 == 1 or req[i] & state != req[i]:
            rtn[i] = False
        temp >>= 1
    
    return [i for i in range(n) if rtn[i]]


dp = [0] * 2 ** n
explored = [False] * 2 ** n  # Explore something when we put it in the queue
q = deque()
q.append(0)
explored[0] = True
dp[0] = 1

while q:
    node = q.popleft()

    for i in possible(node):
        new_node = (1 << i) | node
        dp[new_node] += dp[node]
        if not explored[new_node]:
            q.append(new_node)
            explored[new_node] = True

print(dp[2 ** n - 1])
