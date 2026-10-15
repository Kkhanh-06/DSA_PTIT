import sys
import math
input = sys.stdin.readline

n, k = map(int, input().split())
a = list(map(int, input().split()))

res = 0

def dfs(pos, cnt, lcm):
    global res
    if pos == k:
        if cnt == 0:
            return
        temp = n // lcm
        if cnt % 2 == 1:
            res += temp
        else:
            res -= temp
        return

    # Không chọn a[pos]
    dfs(pos + 1, cnt, lcm)

    # Chọn a[pos]
    g = math.gcd(lcm, a[pos])
    if lcm > n // (a[pos] // g):  # tránh tràn
        return
    new_lcm = lcm * (a[pos] // g)
    dfs(pos + 1, cnt + 1, new_lcm)

dfs(0, 0, 1)
print(res)
