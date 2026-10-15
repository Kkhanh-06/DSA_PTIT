n = int(input())

if n == 1:
    print(1)
elif n == 2 or n == 3:
    print("NO SOLUTION")
else:
    ar_even = [str(i) for i in range(2, n+1, 2)]
    ar_odd = [str(i) for i in range(1, n + 1, 2)]
    if n > 4:
        ar_even.reverse()
        ar_odd.reverse()
    print(' '.join(ar_even+ar_odd))
