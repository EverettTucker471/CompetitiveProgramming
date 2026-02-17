import math


n = int(input())

# password, name, start_year, sus_score
sor = []
for i in range(n):
    tokens = input().strip().split()
    sor.append((tokens[3], tokens[0], int(tokens[1]), int(tokens[2])))

# Year, prefix
m = int(input())
queries = []
for i in range(m):
    tokens = input().strip().split()
    if len(tokens) < 2:
        tokens.append("")
    queries.append((int(tokens[0]), tokens[1]))

sor.sort()  # By password
queries.sort()  # By year

for q in queries:
    prefix = q[1]
    pre_len = len(prefix)

    left = 0
    right = n - 1
    while left <= right:
        mid = (left + right) // 2

        if sor[mid][0][:pre_len] == prefix:
            lower = mid
            right = mid - 1
        elif sor[mid][0][:pre_len] < prefix:
            left = mid + 1
        else:
            right = mid - 1
    
    left = 0
    right = n - 1
    while left <= right:
        mid = (left + right) // 2

        if sor[mid][0][:pre_len] == prefix:
            upper = mid
            left = mid + 1
        elif sor[mid][0][:pre_len:] < prefix:
            left = mid + 1
        else:
            right = mid - 1

    sus_name = ""
    max_sus = -math.inf
    for j in range(lower, upper + 1):
        if sor[j][2] <= q[0]:
            if sor[j][3] > max_sus:
                sus_name = sor[j][1]
                max_sus = sor[j][3]
    
    print(sus_name)

    