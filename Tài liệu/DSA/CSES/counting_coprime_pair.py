import sys
input = sys.stdin.readline

MAX = 10**6 + 1

n = int(input())
a = list(map(int, input().split()))

# Bước 1: đếm tần suất mỗi số
freq = [0] * MAX
for x in a:
    freq[x] += 1

# Bước 2: đếm số phần tử chia hết cho d
cnt = [0] * MAX
for i in range(1, MAX):
    for j in range(i, MAX, i):
        cnt[i] += freq[j]

# Bước 3: tính hàm Möbius
mu = [1] * MAX
is_prime = [True] * MAX
for i in range(2, MAX):
    if is_prime[i]:
        for j in range(i, MAX, i):
            is_prime[j] = False
            mu[j] *= -1
        for j in range(i*i, MAX, i*i):
            mu[j] = 0

# Bước 4: đếm số cặp nguyên tố cùng nhau (GCD = 1)
res = 0
for d in range(1, MAX):
    c = cnt[d]
    if c >= 2:
        res += mu[d] * (c * (c - 1) // 2)

print(res)
