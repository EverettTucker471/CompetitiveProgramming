_ = int(input())

for __ in range(_):
    n, m = map(int, input().split())

    pairs = []
    for i in range(m):
        pairs.append([int(x) for x in input().split()])
    
    rtn = n - 1
    for i in range(m):
        a, b = pairs[i][0], pairs[i][1]
        if a == b - 1:
            rtn -= 1
        elif a > b:
            rtn = -1
            break

    print(rtn)
