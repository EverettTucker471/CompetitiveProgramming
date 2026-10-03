_ = int(input())

for __ in range(_):
    n, p = map(int, input().split())
    s = [int(x) for x in input().split()]

    k = sum(s)
    target = p / k

    rtn = 0
    for i in range(n):
        rtn += ((target * s[i]) ** 2) / s[i]
    print(rtn)
