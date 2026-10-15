n = int(input())
total = n * (n + 1) // 2

if total % 2 != 0:
    print("NO")
else:
    set1 = []
    set2 = []
    target = total // 2

    for i in range(1, n+1):
        if target >= i:
            set1.append(i)
            target -= i
        else:
            set2.append(i)

    print("YES")
    print(len(set1))
    print(*sorted(set1))
    print(len(set2))
    print(*sorted(set2))
