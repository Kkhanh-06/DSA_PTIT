def solve(n, a, b):
    if a + b > n:
        print("NO")
        return

    A = [1, 4, 3, 2]  # Cố định theo đề
    B = [-1] * n
    used = set()

    # Gán lượt B thắng trước (B[i] > A[i])
    b_left = b
    for i in range(n):
        if b_left == 0:
            break
        for x in range(A[i] + 1, n + 1):
            if x not in used:
                B[i] = x
                used.add(x)
                b_left -= 1
                break

    # Gán lượt A thắng sau (B[i] < A[i])
    a_left = a
    for i in range(n):
        if B[i] != -1:
            continue
        if a_left == 0:
            break
        for x in range(1, A[i]):
            if x not in used:
                B[i] = x
                used.add(x)
                a_left -= 1
                break

    # Gán các vị trí còn lại là hòa (B[i] = A[i])
    for i in range(n):
        if B[i] == -1 and A[i] not in used:
            B[i] = A[i]
            used.add(A[i])

    # Nếu vẫn còn vị trí -1 → NO
    if any(x == -1 for x in B):
        print("NO")
        return

    print("YES")
    print(*A)
    print(*B)

n = int(input())
a = int(input())
b = int(input())
solve(n, a, b)
