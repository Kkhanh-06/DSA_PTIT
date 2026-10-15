import sys
input = sys.stdin.readline

n = int(input())
MOD = 10**9+7
output = []

for _ in range(n):
    a, b, c = map(int, input().split())
    b1 = pow(b, c, MOD-1)
    if a == 0 and b1 == 0:
        output.append("1")
    else:
        output.append(str(pow(a, b1, MOD)))

print("\n".join(output))