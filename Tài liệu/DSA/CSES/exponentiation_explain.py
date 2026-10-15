import sys
input = sys.stdin.readline

n = int(input())
MOD = 10**9 +7
output = []

for _ in range(n):
    a, b = map(int, input().split())

    output.append(str(pow(a, b, MOD)))

print("\n".join(output))    