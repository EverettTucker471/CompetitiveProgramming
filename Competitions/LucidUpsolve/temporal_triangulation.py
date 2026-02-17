arr = []
for i in range(5):
    arr.append([float(x) for x in input().strip().split()])

mat = [[0] * 6 for _ in range(5)]
for i in range(5):
    for j in range(6):
        if j <= 3:
            mat[i][j] = -2 * arr[i][j]
        elif j == 4:
            mat[i][j] = 1
        else:
            mat[i][j] = arr[i][-1] ** 2 - sum([x ** 2 for x in arr[i][:4]])


# Triangulation
for j in range(5):
    for i in range(j + 1, 5):
        if mat[j][j] != 0:
            factor = mat[i][j] / mat[j][j]
            for k in range(6):
                mat[i][k] -= factor * mat[j][k]

# Diagonalization
for j in range(4, 0, -1):
    for i in range(j - 1, -1, -1):
        if mat[j][j] != 0:
            factor = mat[i][j] / mat[j][j]
            for k in range(6):
                mat[i][k] -= factor * mat[j][k]

# Normalization
for j in range(5):
    if mat[j][j] != 0:
        mat[j][-1] /= mat[j][j]
        mat[j][j] = 1

# Answer extraction
ans = [round(mat[i][-1]) for i in range(4)]
print(ans[0], ans[1], ans[2], ans[3])

