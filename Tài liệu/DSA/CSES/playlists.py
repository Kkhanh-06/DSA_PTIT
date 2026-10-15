n = int(input())  # Nhập số lượng bài hát
playlist = list(map(int, input().split()))  # Nhập danh sách các bài hát (theo mã số hoặc ID)

seen = set()  # Tập hợp để lưu các bài hát đang có trong cửa sổ hiện tại (dùng để kiểm tra trùng lặp nhanh)
res = 0       # Kết quả: độ dài lớn nhất của đoạn con không có bài nào bị lặp
left = 0      # Con trỏ bên trái của cửa sổ trượt

# Duyệt qua từng bài hát với con trỏ phải
for right in range(n):
    # Nếu bài hát hiện tại đã xuất hiện, dịch con trỏ trái để loại bỏ bài bị trùng
    while playlist[right] in seen:
        seen.remove(playlist[left])  # Loại bài hát ở vị trí left ra khỏi tập
        left += 1                    # Dịch con trỏ trái sang phải

    seen.add(playlist[right])  # Thêm bài hát hiện tại vào tập
    res = max(res, right - left + 1)  # Cập nhật độ dài lớn nhất nếu cần

print(res)  # In ra kết quả
