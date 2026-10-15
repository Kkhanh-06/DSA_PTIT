n = int(input())
grid = [[0] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        used = set()

        # Tìm các số đã dùng trong hàng i (trái -> phải)
        for k in range(j):
            used.add(grid[i][k])
        # Tìm các số đã dùng trong cột j (trên -> dưới)
        for k in range(i):
            used.add(grid[k][j])

        # Tìm số nhỏ nhất không thuộc tập used
        val = 0
        while val in used:
            val += 1

        grid[i][j] = val

# In kết quả
for row in grid:
    print(*row)

# n = 3
# 0 _ _
# _ _ _
# _ _ _

# 0 1 _
# _ _ _
# _ _ _

# 0 1 2
# _ _ _
# _ _ _

# 0 1 2
# 1 _ _
# _ _ _

# 0 1 2
# 1 0 _
# _ _ _

# 0 1 2
# 1 0 3
# _ _ _

# 0 1 2
# 1 0 3
# 2 _ _

# 0 1 2
# 1 0 3
# 2 3 _

# 0 1 2
# 1 0 3
# 2 3 0
