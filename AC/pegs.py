def check(pos):
    return 0 <= pos[0] < 7 and 0 <= pos[1] < 7

grid = []
for i in range(2):
    line = input()
    grid.append(f"  {line.strip()}  ")
for i in range(3):
    line = input()
    grid.append(line.strip())
for i in range(2):
    line = input()
    grid.append(f"  {line.strip()}  ")

jump = [(0, 2), (2, 0), (-2, 0), (0, -2)]

n = len(grid)
m = len(grid[0])

rtn = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'o':
            for d in jump:
                temp = (i + d[0], j + d[1])
                if check(temp) and grid[temp[0]][temp[1]] == '.' and grid[i + d[0] // 2][j + d[1] // 2] == 'o':
                    rtn += 1

print(rtn)