n = int(input())
ar = list(map(int, input().split()))
s = 0
for i in range(1, len(ar)):
    if ar[i] < ar[i-1]:
        s += ar[i-1] - ar[i]
        ar[i] = ar[i-1]
print(s)