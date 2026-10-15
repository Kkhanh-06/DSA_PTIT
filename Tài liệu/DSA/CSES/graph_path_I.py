MOD = 10**9 + 7

def mat_mul(A, B):
    n = len(A)
    res = [[0] * n for _ in range(n)]
    for i in range(n):
        for k in range(n):
            if A[i][k]:
                for j in range(n):
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD
    return res

def mat_pow(mat, power):
    n = len(mat)
    res = [[int(i == j) for j in range(n)] for i in range(n)]  # ma trận đơn vị
    while power:
        if power % 2:
            res = mat_mul(res, mat)
        mat = mat_mul(mat, mat)
        power //= 2
    return res

# Input
n, m, k = map(int, input().split())
A = [[0] * n for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    A[u - 1][v - 1] += 1

res = mat_pow(A, k)
print(res[0][n - 1])
