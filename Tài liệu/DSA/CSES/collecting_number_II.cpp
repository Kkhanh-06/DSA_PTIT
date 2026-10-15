#include <iostream>
#include <vector>
#include <algorithm>

// Giới hạn số phần tử tối đa
const int maxN = 2e5 + 5;

int N, M;          // N: số phần tử ban đầu, M: số truy vấn
int cnt;           // Số lượng "đoạn tăng" (số lần tăng giá trị khi duyệt mảng theo thứ tự ban đầu)
int x[maxN];       // Mảng chứa thứ tự ban đầu
int pos[maxN];     // Mảng chứa vị trí của từng giá trị trong mảng x

// Hàm cập nhật số đoạn tăng giảm khi hoán đổi hai phần tử ở vị trí a và b
void update(int a, int b) {
    // Xử lý ảnh hưởng của phần tử x[a] đến các phần tử lân cận trước khi hoán đổi

    // Kiểm tra phần tử nhỏ hơn liền trước x[a]
    if (pos[x[a] - 1] <= pos[x[a]] && b < pos[x[a] - 1]) cnt++;    // Đoạn mới hình thành
    if (pos[x[a] - 1] > pos[x[a]] && b >= pos[x[a] - 1]) cnt--;    // Đoạn cũ bị phá vỡ

    // Kiểm tra phần tử lớn hơn liền sau x[a]
    if (pos[x[a] + 1] >= pos[x[a]] && b > pos[x[a] + 1]) cnt++;
    if (pos[x[a] + 1] < pos[x[a]] && b <= pos[x[a] + 1]) cnt--;

    // Cập nhật vị trí mới cho phần tử x[a]
    pos[x[a]] = b;

    // Xử lý tương tự cho x[b]
    if (pos[x[b] - 1] <= pos[x[b]] && a < pos[x[b] - 1]) cnt++;
    if (pos[x[b] - 1] > pos[x[b]] && a >= pos[x[b] - 1]) cnt--;
    if (pos[x[b] + 1] >= pos[x[b]] && a > pos[x[b] + 1]) cnt++;
    if (pos[x[b] + 1] < pos[x[b]] && a <= pos[x[b] + 1]) cnt--;

    // Cập nhật vị trí mới cho x[b]
    pos[x[b]] = a;

    // Hoán đổi giá trị trong mảng x
    std::swap(x[a], x[b]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Nhập số phần tử và số truy vấn
    std::cin >> N >> M;

    // Đọc mảng x và cập nhật vị trí ban đầu của từng phần tử
    for (int i = 1; i <= N; ++i) {
        std::cin >> x[i];
        pos[x[i]] = i;
    }

    // Đảm bảo phần tử x[N+1] không ảnh hưởng đến logic (bổ sung an toàn)
    pos[N + 1] = N + 1;

    // Tính số đoạn tăng ban đầu (ban đầu luôn có ít nhất 1 đoạn)
    cnt = 1;
    for (int i = 1, ptr = 0; i <= N; ++i) {
        if (ptr > pos[i]) cnt++;  // Nếu vị trí phần tử hiện tại nhỏ hơn phần tử trước đó, là đoạn mới
        ptr = pos[i];             // Cập nhật vị trí trước đó
    }

    // Xử lý M truy vấn hoán đổi
    for (int i = 0; i < M; ++i) {
        int a, b;
        std::cin >> a >> b;
        update(a, b);            // Cập nhật số đoạn sau khi hoán đổi
        std::cout << cnt << '\n'; // In kết quả sau mỗi truy vấn
    }

    return 0;
}
