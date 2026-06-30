s = input()
n = len(s)

def search(l, r, incon):
    # Search left from previous incongruence
    count = 0
    dist = 0
    incon_letters = [s[i] for i in incon]

    # Checking the center - always optimal
    if l + r % 2 == 0 and s[(l + r) // 2] in incon_letters:
        return r - l - 1
    
    for i in range(incon[0] - 1, -1, -1):
        count += 1
        if s[i] in incon_letters:
            dist = max(dist, count)
    
    count = 0
    for i in range(incon[1] + 1, n):
        count += 1
        if s[i] in incon_letters:
            dist = max(dist, count)
    
    if dist > 0:
        if dist > r - incon[1]:
            # outside of the considered interval
            return r - l - 1
        else:
            # go out a distance dist
            return incon[1] - incon[0] - 1 + 2 * dist
    else:
        # No other matches found, return the inner
        return incon[1] - incon[0] - 1


def check(l: int, r: int) -> int:
    incon = None
    swapped = False
    while l >= 0 and r < n:
        if s[l] == s[r]:
            l -= 1
            r += 1
        elif not swapped:
            if incon:
                # Second incongruence
                a = set([s[i] for i in incon])
                b = set([s[l], s[r]])
                union = len(a.union(b))
                if union == 2:
                    # Both can be replaced
                    swapped = True
                    l -= 1
                    r += 1
                elif union == 3:
                    # replace the inner one and terminate
                    return r - l - 1
                else:
                    # No overlap, search for the first swap elsewhere
                    return search(l, r, incon)
            else:
                # First incongruence - continue
                incon = [l, r]
                l -= 1
                r += 1
        else:
            # We can't swap again so break
            break
    if incon:
        if swapped:
            # Incongruence was resolved
            return r - l - 1
        else:
            # One incongruence remains
            return search(l, r, incon)
    else:
        # No incongruences
        return r - l - 1
    
# Odd Case -> Start at every single index:
longest = 1
for i in range(1, n - 1):
    longest = max(longest, check(i - 1, i + 1))

# Even Case -> Start at every pair of indices
for i in range(n - 1):
    longest = max(longest, check(i, i + 1))

print(longest)
