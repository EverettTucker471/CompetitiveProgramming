import math

def inverse(k, m):
    return k if k <= 1 else m - (m // k) * inverse(m % k, m) % m

while True:
    n, t = map(int, input().strip().split())

    if n == 0:
        exit()

    for i in range(t):
        tokens = input().strip().split()
        x, y = int(tokens[0]), int(tokens[2])

        if tokens[1] == "/":
            k = math.gcd(y, n)
            res = -1 if (y == 0 or k != 1) else (x * inverse(y, n)) % n
        elif tokens[1] == "+":
            res = (x + y) % n
        elif tokens[1] == "*":
            res = (x * y) % n
        else:
            res = (x - y + n) % n
        
        print(res)
