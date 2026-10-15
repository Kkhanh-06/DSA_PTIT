MOD = 10**9+7

def resolve(n):
    res = 0
    i = 1
    while i <= n:
        k = n//i
        last = n//k
        total = (i+last)*(last - i +1)//2
        res += k*total
        res %= MOD
        i = last + 1
    return res

n = int(input())
print(resolve(n))