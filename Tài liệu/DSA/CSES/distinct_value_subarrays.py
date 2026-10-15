from collections import Counter
from itertools import combinations

def count_distinct_subsequences(a):
    mod = 10**9 + 7  # Đặt modulo để tránh tràn số

    # Đếm số lần xuất hiện của mỗi phần tử trong mảng
    counter = Counter(a)

    # Lấy danh sách các phần tử phân biệt
    keys = list(counter.keys())
    n = len(keys)
    res = 0  # Kết quả cuối cùng: số dãy con thỏa mãn

    # Duyệt tất cả tập con không rỗng của tập các phần tử phân biệt
    for l in range(1, n + 1):
        for subset in combinations(keys, l):  # Tập con độ dài l
            prod = 1  # Số cách tạo subsequence từ tập con hiện tại
            for x in subset:
                # Với mỗi phần tử x, có counter[x] vị trí để chọn
                prod *= counter[x]
            res += prod
            res %= mod  # Đảm bảo không bị overflow

    return res

n = int(input())

arr = list(map(int, input().split()))
print(count_distinct_subsequences(arr))
