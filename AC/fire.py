from collections import deque

n, m = map(int, input().split())

grid = []
joe_q = deque()
fire_q = deque()

joe_exp = set()
fire_exp = set()

for i in range(n):
    s = input()
    grid.append(s)

    for j in range(m):
        if s[j] == 'J':
            joe_q.append((i, j, 0))
            joe_exp.add((i, j))
        elif s[j] == 'F':
            fire_q.append((i, j, 0))
            fire_exp.add((i, j))

def valid(i, j):
    """Returns the valid adjacent steps for a given position"""
    rtn = []

    # Up
    if i > 0 and grid[i - 1][j] != '#':
        rtn.append((i - 1, j))
    # Right
    if j < m - 1 and grid[i][j + 1] != '#':
        rtn.append((i, j + 1))
    # Down
    if i < n - 1 and grid[i + 1][j] != '#':
        rtn.append((i + 1, j))
    # Left
    if j > 0 and grid[i][j - 1] != '#':
        rtn.append((i, j - 1))

    return rtn


for t in range(n * m):
    while len(joe_q) > 0 and joe_q[0][2] == t:
        joe_i, joe_j, joe_t = joe_q.popleft()

        if (joe_i, joe_j) in fire_exp:
                    continue
        
        if joe_i == 0 or joe_i == n - 1 or joe_j == 0 or joe_j == m - 1:
            print(joe_t + 1)
            exit()

        for adj in valid(joe_i, joe_j):
            if adj not in joe_exp and adj not in fire_exp:
                joe_q.append((adj[0], adj[1], t + 1))
                joe_exp.add(adj)

    while len(fire_q) > 0 and fire_q[0][2] == t:
        fire_i, fire_j, fire_t = fire_q.popleft()

        for adj in valid(fire_i, fire_j):
            if (adj[0], adj[1]) not in fire_exp:
                fire_exp.add(adj)
                fire_q.append((adj[0], adj[1], t + 1))

print("IMPOSSIBLE")