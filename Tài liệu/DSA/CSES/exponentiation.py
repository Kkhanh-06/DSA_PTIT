import sys

MOD = 10**9 + 7
input = sys.stdin.readline


n = int(input())
res = []
for _ in range(n):
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        res.append("1")
    else:
        res.append(str(pow(a, b, MOD)))
print("\n".join(res))

