import math

MOD = 10**9 + 7

def pow_mod(a, b, mod):
    result = 1
    a %= mod
    while b > 0:
        if b % 2 == 1:
            result = result * a % mod
        a = a * a % mod
        b //= 2
    return result

def modinv(a, mod):
    # Nghịch đảo modulo: a^(-1) mod p = a^(p-2) mod p (vì MOD là số nguyên tố)
    return pow_mod(a, mod - 2, mod)

def count_necklaces(n, m):
    total = 0
    for k in range(n):
        g = math.gcd(n, k)
        total = (total + pow_mod(m, g, MOD)) % MOD
    # Chia cho n (chia modulo)
    return total * modinv(n, MOD) % MOD

# Đọc input
n, m = map(int, input().split())
print(count_necklaces(n, m))
