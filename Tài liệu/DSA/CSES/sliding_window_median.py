import sys
import heapq

# Tính median (trung vị) của mỗi cửa sổ trượt độ dài k
# Sử dụng 2 heap + kỹ thuật xóa lười (lazy deletion) để đạt O(n log k)

def sliding_window_median(arr, k):
    low = []    # max-heap (lưu số âm của giá trị để mô phỏng heap lớn nhất)
    high = []   # min-heap (lưu giá trị bình thường)
    delayed = {}  # map: giá trị -> số lần cần xóa (xóa lười)

    # Biến đếm số phần tử hợp lệ trong mỗi heap (đã trừ đi phần tử bị đánh dấu xóa)
    small_size = 0
    large_size = 0

    def prune(heap):
        """Loại bỏ các phần tử ở đỉnh heap nếu chúng đã bị đánh dấu xóa."""
        while heap:
            if heap is low:
                val = -heap[0]  # low lưu số âm, nên đảo dấu
            else:
                val = heap[0]
            if delayed.get(val, 0):
                # Giảm số lần xóa chờ xử lý
                delayed[val] -= 1
                if delayed[val] == 0:
                    del delayed[val]
                # Thực sự pop khỏi heap
                heapq.heappop(heap)
            else:
                break  # Phần tử đỉnh hợp lệ thì dừng

    def balance():
        """Cân bằng 2 heap sao cho:
           - small_size == large_size hoặc small_size == large_size + 1
           - Và loại bỏ phần tử rác ở đỉnh nếu cần
        """
        nonlocal small_size, large_size
        if small_size > large_size + 1:
            prune(low)
            # Chuyển phần tử lớn nhất từ low sang high
            v = -heapq.heappop(low)
            small_size -= 1
            heapq.heappush(high, v)
            large_size += 1
            prune(low)
        elif small_size < large_size:
            prune(high)
            # Chuyển phần tử nhỏ nhất từ high sang low
            v = heapq.heappop(high)
            large_size -= 1
            heapq.heappush(low, -v)
            small_size += 1
            prune(high)

    def insert(num):
        """Thêm một số mới vào cấu trúc."""
        nonlocal small_size, large_size
        if not low or num <= -low[0]:
            heapq.heappush(low, -num)
            small_size += 1
        else:
            heapq.heappush(high, num)
            large_size += 1
        balance()

    def erase(num):
        """Đánh dấu xóa một số (xóa lười)."""
        nonlocal small_size, large_size
        delayed[num] = delayed.get(num, 0) + 1
        if low and num <= -low[0]:
            small_size -= 1
            if num == -low[0]:
                prune(low)
        else:
            large_size -= 1
            if high and num == high[0]:
                prune(high)
        balance()

    # Khởi tạo cửa sổ đầu tiên
    for i in range(k):
        insert(arr[i])

    medians = []
    # Median = phần tử lớn nhất trong low
    medians.append(-low[0])

    # Trượt cửa sổ
    for i in range(k, len(arr)):
        insert(arr[i])         # thêm phần tử mới
        erase(arr[i - k])      # xóa phần tử cũ
        medians.append(-low[0])

    return medians


if __name__ == "__main__":
    data = sys.stdin.read().strip().split()
    if not data:
        sys.exit(0)
    it = iter(data)
    n = int(next(it))
    k = int(next(it))
    arr = [int(next(it)) for _ in range(n)]
    res = sliding_window_median(arr, k)
    print(' '.join(map(str, res)))
