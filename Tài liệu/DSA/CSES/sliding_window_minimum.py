import sys
from collections import deque
input = sys.stdin.readline

# Đọc n: số phần tử, k: kích thước cửa sổ
n, k = map(int, input().split())

# Đọc các tham số sinh dãy
x, a, b, c = map(int, input().split())

# Deque để lưu các phần tử ứng viên làm min trong cửa sổ
# Mỗi phần tử trong deque là tuple (chỉ số, giá trị)
dq = deque()

# Kết quả XOR của các giá trị min cửa sổ
xor_result = 0

# Duyệt qua n phần tử, vừa sinh giá trị vừa xử lý cửa sổ
for i in range(n):
    if i == 0:
        # Phần tử đầu tiên là x
        val = x
    else:
        # Sinh phần tử tiếp theo theo công thức
        x = (a * x + b) % c
        val = x

    # 1. Loại bỏ các phần tử nằm ngoài cửa sổ hiện tại
    # Nếu index <= i - k nghĩa là nó ở bên trái ngoài cửa sổ
    while dq and dq[0][0] <= i - k:
        dq.popleft()

    # 2. Loại bỏ các phần tử ở cuối deque có giá trị >= val
    # Vì chúng sẽ không bao giờ được chọn làm min trong tương lai
    while dq and dq[-1][1] >= val:
        dq.pop()

    # 3. Thêm phần tử mới vào cuối deque
    dq.append((i, val))

    # 4. Nếu cửa sổ đủ k phần tử, lấy min (đầu deque) và XOR vào kết quả
    if i >= k - 1:
        xor_result ^= dq[0][1]

# In kết quả cuối cùng
print(xor_result)
