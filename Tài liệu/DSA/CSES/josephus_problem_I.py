from collections import deque

n = int(input())
q = deque(range(1, n+1))
res = []

while q:
    q.append(q.popleft())  # Bỏ qua 1 đứa (đẩy ra sau)
    res.append(q.popleft())  # Loại đứa tiếp theo

print(*res)

# ví dụ:
# [1 3 4 2 5 6]
# [3 4 2 5 6 1]
# [4 2 5 6 1]
# [2 5 6 1 4]
# [5 6 1 4]
# [6 1 4 5]
# [1 4 5]
# [4 5 1]
# [5 1]
# [1 5]
# [5]
