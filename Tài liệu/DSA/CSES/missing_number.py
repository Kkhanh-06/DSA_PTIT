n = int(input())
ar = list(map(int, input().split()))
s1 = 0
for i in range(1, n+1):
    s1 += i
s2 = sum(ar)
print(s1-s2)