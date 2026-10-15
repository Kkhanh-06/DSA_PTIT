n = int(input())  # Nhập số lượng đĩa

# Hàm giải bài toán Tháp Hà Nội
# n: số đĩa
# a: cọc nguồn
# b: cọc trung gian
# c: cọc đích
def thapHaNoi(n, a, b, c):
    if n == 1:
        # Trường hợp cơ bản: chỉ có 1 đĩa → di chuyển trực tiếp từ a sang c
        print(a + " " + c)
    else:
        # Bước 1: Di chuyển n-1 đĩa từ cọc a sang cọc b (sử dụng c làm trung gian)
        thapHaNoi(n-1, a, c, b)
        # Bước 2: Di chuyển đĩa lớn nhất còn lại từ cọc a sang cọc c
        print(a + " " + c)
        # Bước 3: Di chuyển n-1 đĩa từ cọc b sang cọc c (sử dụng a làm trung gian)
        thapHaNoi(n-1, b, a, c)

# In tổng số bước cần thực hiện: 2^n - 1
print(2**n - 1)

# Gọi hàm thực hiện với 3 cọc: 1 (nguồn), 2 (trung gian), 3 (đích)
thapHaNoi(n, "1", "2", "3")


# thapHaNoi(3, 1, 2, 3)
# ├── thapHaNoi(2, 1, 3, 2)
# │   ├── thapHaNoi(1, 1, 2, 3)
# │   │   └── print(1 3)
# │   └── print(1 2)
# │   └── thapHaNoi(1, 3, 1, 2)
# │       └── print(3 2)
# ├── print(1 3)
# └── thapHaNoi(2, 2, 1, 3)
#     ├── thapHaNoi(1, 2, 3, 1)
#     │   └── print(2 1)
#     └── print(2 3)
#     └── thapHaNoi(1, 1, 2, 3)
#         └── print(1 3)
