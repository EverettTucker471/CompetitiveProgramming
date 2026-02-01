n, e = map(int, input().strip().split())

reverse_names = []
names = {}
dir = []
ranges = []
for i in range(n):
    tokens = input().strip().split()
    names[tokens[0]] = i
    reverse_names.append(tokens[0])
    dir.append(tokens[2]=="up")
    if i == 0:
        ranges.append([1, int(tokens[1])])
    else:
        ranges.append([ranges[i - 1][1] + 1, int(tokens[1]) + ranges[i - 1][1]])

queries = []
for k in range(e):
    tokens = input().strip().split()
    queries.append((tokens[0], int(tokens[1]), int(tokens[2])))

for q in queries:
    # Calculate the global year
    idx = names[q[0]]

    if dir[idx]:
        global_year = ranges[idx][1] + (q[1] - 1)
    else:
        global_year = ranges[idx][0] - (q[1] - 1)

    global_year -= q[2]

    # Find the correct dynasty
    dynasty_idx = 0
    for j in range(n):
        if ranges[j][0] <= global_year <= ranges[j][1]:
            dynasty_idx = j
            break
    
    output_name = reverse_names[dynasty_idx]

    if dir[dynasty_idx]:
        # If up
        output_year = global_year - (ranges[dynasty_idx][0] - 1)
    else:
        # If down
        output_year = ranges[dynasty_idx][1] - (global_year - 1)
    
    print(output_name, output_year)
    
