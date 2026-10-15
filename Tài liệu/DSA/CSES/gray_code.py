n = int(input())  # Nhập độ dài chuỗi Gray code cần sinh

# Hàm đệ quy sinh Gray code
def sinh_gray(n):
    if n == 0:
        return ['']  # Trường hợp cơ bản: chuỗi rỗng
    prev = sinh_gray(n - 1)  # Sinh dãy Gray code độ dài n-1
    result = []

    # Phần đầu: thêm '0' phía trước từng chuỗi trong dãy cũ
    for code in prev:
        result.append('0' + code)

    # Phần sau: thêm '1' phía trước từng chuỗi trong dãy cũ nhưng theo thứ tự ngược
    for code in reversed(prev):
        result.append('1' + code)

    return result

# Gọi hàm và in từng chuỗi Gray code ra
gray_codes = sinh_gray(n)
for code in gray_codes:
    print(code)

# sinh_gray(2)
# ├── sinh_gray(1)
# │   ├── sinh_gray(0)
# │   │   → ['']
# │   └── build từ [''] → ['0', '1']
# ├── Build từ ['0', '1']
# │   ├── Thêm '0' trước: ['00', '01']
# │   ├── Thêm '1' trước reversed(['0', '1']) = ['1', '0'] → ['11', '10']
# └── Kết quả cuối cùng: ['00', '01', '11', '10']