import math
from collections import deque


spatial = [(0, 0), (-1, 0), (0, -1), (1, 0), (0, 1)]
time = [-1, 0, 1]

n, m = map(int, input().strip().split())

grid = []
for i in range(n):
    grid.append([x for x in input().strip()])

doors = {}
num_doors = int(input())
for i in range(num_doors):
    x, y, start, end = map(int, input().strip().split())
    doors[(x, y)] = [start, end]

for i in range(n):
    for j in range(m):
        if grid[i][j] == 'S':
            start = (i, j, 0)
        elif grid[i][j] == 'E':
            end = (i, j)


def checkPosOpen(node):
    if 0 <= node[0] <= n and 0 <= node[1] <= m and 0 <= node[2] <= 200:
        if grid[node[0]][node[1]] == 'D':
            door = doors[(node[0], node[1])]
            return door[0] <= node[2] <= door[1]
        elif grid[node[0]][node[1]] != '#':
            return True
    return False


def getAdjacentStates(node):
    rtn = []
    for s in spatial:
        for t in time:
            pos = (node[0] + s[0], node[1] + s[1], node[2] + t)
            if checkPosOpen(pos):
                rtn.append(pos)
    return rtn


q = deque()
dist = {}
q.append(start)
dist[start] = 0
visited = set()

while q:
    node = q.popleft()
    visited.add(node)

    if (node[0], node[1]) == end:
        print(dist[node])
        exit()

    for x in getAdjacentStates(node):
        if x not in visited and dist.get(x, -1) < dist[node]:
            dist[x] = min(dist.get(x, math.inf), dist[node] + 1)
            q.append(x)

