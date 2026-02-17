import math

n = int(input())

while n > 0:
    positions = []
    for i in range(n):
        pos_string = input().strip().split()

        pos = [float(x) for x in pos_string[:2]]
        heading = 0

        # updating the heading and position
        for j in range(2, len(pos_string), 2):
            if pos_string[j] == "walk":
                mag = float(pos_string[j + 1])
                pos[0] += mag * math.cos(math.pi / 180 * heading)
                pos[1] += mag * math.sin(math.pi / 180 * heading)
            elif pos_string[j] == "start":
                heading = float(pos_string[j + 1])
            elif pos_string[j] == "turn":
                heading += float(pos_string[j + 1])

        positions.append(pos)

    # Compute center, and distance
    center = [0, 0]
    for pos in positions:
        center[0] += pos[0]
        center[1] += pos[1]
    center[0] /= n
    center[1] /= n

    # Computing worst distance
    worst_dist = 0
    for pos in positions:
        d = math.sqrt((center[0] - pos[0]) ** 2 + (center[1] - pos[1]) ** 2)
        worst_dist = max(d, worst_dist)
    
    print(center[0], center[1], worst_dist)
    n = int(input())