k = int(input())  # Nhập kích thước tối đa của bàn cờ (tính từ 1 đến k)

# Duyệt qua tất cả các bàn cờ kích thước từ 1x1 đến kxk
for i in range(1, k + 1):
    # Tổng số cách chọn 2 ô khác nhau trên bàn cờ i x i
    # Công thức tổ hợp: C(n, 2) = n*(n-1)/2 với n = i*i
    total = i * i * (i * i - 1) // 2

    # Số cặp quân mã có thể tấn công nhau
    # Trên bàn cờ i x i, mỗi hình chữ nhật 2x3 hoặc 3x2 tạo ra 4 cách để đặt 2 quân mã tấn công nhau
    # Số hình chữ nhật 2x3 là (i - 1) * (i - 2)
    # Số hình chữ nhật 3x2 cũng là (i - 1) * (i - 2)
    attack = 4 * (i - 1) * (i - 2)

    # Số cách đặt 2 quân mã mà không tấn công nhau = tổng số cách - số cách bị tấn công
    safe = total - attack

    print(safe)
