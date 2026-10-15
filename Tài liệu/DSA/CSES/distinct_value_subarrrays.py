def count_distinct_subarrays(a):
    n = len(a)           # Độ dài mảng đầu vào
    seen = []         # Tập hợp các phần tử đang có trong cửa sổ (để kiểm tra trùng)
    left = 0             # Con trỏ trái của cửa sổ (sliding window)
    ans = 0              # Tổng số subarray thỏa mãn (mọi phần tử đều khác nhau)

    # Duyệt con trỏ phải từ trái sang phải
    for right in range(n):
        # Nếu phần tử tại vị trí right đã có trong cửa sổ
        # thì dịch con trỏ trái sang phải để loại bỏ phần tử trùng
        while a[right] in seen:
            seen.remove(a[left])  # Bỏ phần tử ở đầu cửa sổ
            left += 1             # Di chuyển cửa sổ sang phải

        # Thêm phần tử mới vào cửa sổ
        seen.append(a[right])

        # Với mỗi right, số subarray kết thúc tại right là (right - left + 1)
        # vì các subarray hợp lệ là: [a[right]], [a[right-1:right]], ..., [a[left:right]]
        ans += (right - left + 1)

    return ans  # Trả về tổng số subarray thỏa mãn điều kiện

n = int(input())
arr = list(map(int, input().split()))

print(count_distinct_subarrays(arr))
