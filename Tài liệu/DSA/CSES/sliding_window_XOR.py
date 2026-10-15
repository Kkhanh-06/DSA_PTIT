import sys
input = sys.stdin.readline

n, k = map(int, input().split())
x, a, b, c = map(int, input().split())

# Mảng vòng để lưu k phần tử trong cửa sổ
window = [0] * k
window[0] = x

# Tính XOR của cửa sổ đầu tiên
xor_window = x
for i in range(1, k):
    x = (a * x + b) % c
    window[i] = x
    xor_window ^= x

# Kết quả là XOR của tất cả XOR cửa sổ
result = xor_window

# Duyệt qua các phần tử còn lại
for i in range(k, n):
    x = (a * x + b) % c
    idx = i % k  # vị trí vòng tròn

    # Loại phần tử cũ và thêm phần tử mới
    xor_window ^= window[idx]  # bỏ phần tử cũ
    xor_window ^= x            # thêm phần tử mới

    # Ghi đè phần tử cũ bằng phần tử mới
    window[idx] = x

    # Cập nhật kết quả
    result ^= xor_window

print(result)
