# Nhập số nguyên n: độ dài của mảng (chứa các số từ 1 đến n)
n = int(input())

# Nhập mảng gồm n số nguyên, là hoán vị của các số từ 1 đến n
arr = list(map(int, input().split()))

# Tạo mảng pos để lưu vị trí (chỉ số) của từng số trong arr
# pos[x] sẽ cho biết vị trí của số x trong mảng ban đầu
pos = [0] * (n + 1)
for i in range(n):
    pos[arr[i]] = i  # Gán vị trí của phần tử arr[i] là i

# Biến đếm số vòng cần để thu thập các số từ 1 đến n theo thứ tự tăng
rounds = 1  # Ban đầu luôn cần ít nhất 1 vòng

# Duyệt các số từ 2 đến n
for i in range(2, n + 1):
    # Nếu vị trí của số i nhỏ hơn vị trí của số i-1
    # tức là ta phải bắt đầu một vòng mới để thu thập số i
    if pos[i] < pos[i - 1]:
        rounds += 1  # Tăng số vòng lên

# In ra tổng số vòng cần thiết
print(rounds)
