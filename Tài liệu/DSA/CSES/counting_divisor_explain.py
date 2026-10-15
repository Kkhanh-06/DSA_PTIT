import sys
input = sys.stdin.readline

MAX = 10**5+7
divisor = [0]*MAX

for i in range(1, MAX):
    for j in range(i , MAX, i):
        divisor[j] += 1

output = []

for _ in range(int(input())):
    x = int(input())
    output.append(str(divisor[x]))

print("\n".join(output))