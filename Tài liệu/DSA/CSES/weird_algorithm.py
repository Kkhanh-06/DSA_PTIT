n = int(input())
ar = [n]
while n != 1:
    if n % 2 == 0:
        n /= 2
        ar.append(int(n))
    else:
        n = n * 3 + 1
        ar.append(int(n))
print(*ar)