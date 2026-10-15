#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  // Nhập số lượng đồng xu

    vector<long long> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];  // Nhập giá trị từng đồng xu
    }

    sort(coins.begin(), coins.end());  // Sắp xếp các đồng xu theo thứ tự tăng dần

    long long res = 1;  // res là tổng nhỏ nhất chưa thể tạo được, khởi đầu là 1

    for (int i = 0; i < n; ++i) {
        // Nếu đồng xu hiện tại lớn hơn res, thì không thể tạo được tổng = res
        if (coins[i] > res) {
            break;  // Dừng lại vì không thể tạo ra res từ các đồng xu trước đó
        }
        // Ngược lại, ta có thể tạo được tất cả các tổng từ 1 đến res + coins[i] - 1
        res += coins[i];  // Cập nhật giá trị nhỏ nhất chưa thể tạo ra
    }

    cout << res << "\n";  // In ra kết quả: tổng nhỏ nhất không thể tạo thành từ tập con các đồng xu
    return 0;
}
