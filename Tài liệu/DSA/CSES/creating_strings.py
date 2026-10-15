from itertools import permutations

s = input()
perm = set(permutations(s))
result = sorted([''.join(i) for i in perm])

print(len(result))
for i in result:
    print(i)