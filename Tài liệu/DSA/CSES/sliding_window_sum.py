import sys
input = sys.stdin.readline

# Đọc n, k
n, k = map(int, input().split())

# Đọc các tham số sinh số
x, a, b, c = map(int, input().split())

# Tạo mảng vòng để lưu k phần tử gần nhất trong cửa sổ
window = [0] * k
window[0] = x  # phần tử đầu tiên

# Tính tổng của cửa sổ đầu tiên
sum_window = x
for i in range(1, k):
    # Sinh phần tử tiếp theo theo công thức
    x = (a * x + b) % c
    window[i] = x
    sum_window += x  # cộng vào tổng cửa sổ

# Giá trị XOR kết quả ban đầu chính là tổng cửa sổ đầu tiên
xor_result = sum_window

# Duyệt các phần tử từ vị trí k đến n-1 (0-based)
for i in range(k, n):
    # Sinh phần tử mới
    x = (a * x + b) % c

    # Xác định vị trí trong mảng vòng cần thay thế
    idx = i % k

    # Cập nhật tổng cửa sổ: trừ phần tử cũ, cộng phần tử mới
    sum_window += x - window[idx]

    # Ghi đè phần tử cũ trong mảng vòng
    window[idx] = x

    # XOR tổng cửa sổ vào kết quả
    xor_result ^= sum_window

# In kết quả cuối cùng
print(xor_result)
