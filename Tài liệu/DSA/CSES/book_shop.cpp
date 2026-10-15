#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x; // n: số cuốn sách, x: số tiền tối đa có thể chi

    vector<int> h(n), s(n); // h[i]: giá tiền cuốn sách thứ i, s[i]: độ yêu thích của cuốn sách thứ i

    // Nhập giá tiền của từng cuốn sách
    for (int i = 0; i < n; ++i) cin >> h[i];

    // Nhập độ yêu thích của từng cuốn sách
    for (int i = 0; i < n; ++i) cin >> s[i];

    // total[j]: độ yêu thích tối đa có thể đạt được với số tiền j
    vector<int> total(x + 1, 0);

    // Duyệt từng cuốn sách
    for (int i = 0; i < n; ++i) {
        // Duyệt ngược từ x về h[i] để tránh dùng 1 cuốn sách nhiều lần
        for (int j = x; j >= h[i]; --j) {
            // Cập nhật độ yêu thích tối đa nếu mua cuốn sách thứ i
            total[j] = max(total[j], s[i] + total[j - h[i]]);
        }
    }

    // In ra độ yêu thích tối đa với số tiền x
    cout << total[x] << "\n";
}
