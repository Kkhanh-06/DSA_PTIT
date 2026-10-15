#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; // Nhập số lượng phần tử trong dãy

    vector<long long> a(n);
    long long total = 0; // Tổng toàn bộ các phần tử trong dãy

    // Nhập dãy số và tính tổng
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }

    // dp[l][r] = hiệu số điểm (người đang đi - người còn lại)
    // khi xét dãy con từ chỉ số l đến r
    vector<vector<long long>> dp(n, vector<long long>(n));

    // Cơ sở: nếu chỉ còn một phần tử thì người chơi lấy luôn nó
    for (int i = 0; i < n; ++i) dp[i][i] = a[i];

    // Duyệt theo độ dài đoạn (từ 2 đến n)
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l <= n - len; ++l) {
            int r = l + len - 1; // r là chỉ số phải tương ứng
            // Chọn bên trái hoặc bên phải, lấy hiệu điểm tối ưu
            dp[l][r] = max(
                a[l] - dp[l + 1][r], // Chọn a[l], người kia còn đoạn [l+1, r]
                a[r] - dp[l][r - 1]  // Chọn a[r], người kia còn đoạn [l, r-1]
            );
        }
    }

    // Người chơi đầu tiên được (total + dp[0][n-1]) / 2
    // vì: first - second = dp[0][n-1] và first + second = total
    long long first = (total + dp[0][n - 1]) / 2;

    cout << first << '\n'; // In điểm tối đa người đầu tiên có thể đạt được
    return 0;
}
