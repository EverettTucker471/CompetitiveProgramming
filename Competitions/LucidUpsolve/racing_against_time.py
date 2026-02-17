import math


n, e = map(int, input().strip().split())

verts = {}
for i in range(n):
    verts[int(input())] = i

edges = []
for i in range(e):
    tokens = input().strip().split()
    u = verts[int(tokens[0])]
    v = verts[int(tokens[1])]
    rp = int(tokens[2])
    cost = float(tokens[3].split("/")[0]) / int(tokens[3].split("/")[1])
    edges.append((u, v, rp, cost))

# Debt, points
dist = [(math.inf, 0) for _ in range(n)]
start = verts[1776]
end = verts[2222]
dist[start] = (0, 0)

update = True
while update:
    update = False
    for edge in edges:
        if dist[edge[0]][0] < math.inf:
            otherTuple = (dist[edge[0]][0] + edge[3], dist[edge[0]][1] - edge[2])
            if dist[edge[1]] > otherTuple:
                dist[edge[1]] = otherTuple
                update = True

print(-dist[end][1])
