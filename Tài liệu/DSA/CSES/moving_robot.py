N = 8  # Bàn cờ 8x8
MOD = 10**9 + 7

k = int(input())

from collections import deque

# Các hướng di chuyển: trái, phải, lên, xuống
dirs = [(-1,0), (1,0), (0,-1), (0,1)]

# Hàm kiểm tra tọa độ có nằm trong bàn cờ không
def in_board(x, y):
    return 0 <= x < N and 0 <= y < N

# Với mỗi robot bắt đầu ở (sx, sy), tính xác suất sau k bước ở mọi ô
def get_final_prob(sx, sy):
    dp = [[[0.0 for _ in range(N)] for _ in range(N)] for _ in range(k+1)]
    dp[0][sx][sy] = 1.0
    for step in range(1, k+1):
        for x in range(N):
            for y in range(N):
                cnt = 0
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if in_board(nx, ny):
                        cnt += 1
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if in_board(nx, ny):
                        dp[step][x][y] += dp[step-1][nx][ny] * (1 / len([
                            (dx, dy) for dx, dy in dirs if in_board(nx + dx, ny + dy)
                        ]))
    return dp[k]

# Với mỗi ô (i, j), tính xác suất nó bị chiếm bởi ít nhất 1 robot
# => P_trống(i,j) = tích (1 - P_robot_r đến (i,j))

empty_expectation = 0.0

# Khởi tạo bảng xác suất cuối cùng cho mỗi robot
# prob_total[i][j] = xác suất 1 robot kết thúc tại (i,j)
prob_accum = [[1.0 for _ in range(N)] for _ in range(N)]

for sx in range(N):
    for sy in range(N):
        prob = get_final_prob(sx, sy)
        for i in range(N):
            for j in range(N):
                prob_accum[i][j] *= (1 - prob[i][j])  # tích (1 - P_r(i,j))

# Tổng kỳ vọng số ô trống = tổng P_trống(i,j)
for i in range(N):
    for j in range(N):
        empty_expectation += prob_accum[i][j]

# In kết quả làm tròn 6 chữ số (round-half-even mặc định)
print(f"{empty_expectation:.6f}")
