#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n; // Nhập số lượng phần tử của mảng
    vector<long long> a(n);

    // Nhập các phần tử của mảng
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Khởi tạo tổng lớn nhất và tổng hiện tại là phần tử đầu tiên
    long long max_sum = a[0];
    long long current_sum = a[0];

    // Duyệt từ phần tử thứ 2 đến cuối mảng
    for (long long i = 1; i < n; ++i) {
        // current_sum: tổng lớn nhất của dãy con kết thúc tại vị trí i
        // Nếu current_sum + a[i] < a[i] thì reset dãy con tại a[i]
        current_sum = max(a[i], current_sum + a[i]);

        // Cập nhật tổng lớn nhất nếu cần
        max_sum = max(max_sum, current_sum);
    }

    // In ra tổng lớn nhất của dãy con liên tiếp
    cout << max_sum << '\n';
    return 0;
}
