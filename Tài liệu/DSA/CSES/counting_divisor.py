import sys
input = sys.stdin.readline

MAX = 10**6 + 1
div_cnt = [0] * MAX

# Tiền xử lý: Tính số ước của mỗi số từ 1 đến 1e6
for i in range(1, MAX):
    for j in range(i, MAX, i):
        div_cnt[j] += 1

# Đọc truy vấn và in kết quả
n = int(input())
output = []
for _ in range(n):
    x = int(input())
    output.append(str(div_cnt[x]))

print("\n".join(output))
