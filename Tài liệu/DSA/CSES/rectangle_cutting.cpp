#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b; // Nhập kích thước hình chữ nhật a x b

    // Khởi tạo mảng dp[a+1][b+1] với giá trị rất lớn (1e9),
    // dp[i][j] là số lần cắt tối thiểu để chia hình chữ nhật i x j thành các hình vuông
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));

    // Duyệt qua tất cả các hình chữ nhật có kích thước từ 1x1 đến axb
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0; // Nếu là hình vuông thì không cần cắt
            } else {
                // Cắt dọc: chia hình chữ nhật i x j thành hai hình (k x j) và ((i-k) x j)
                for (int k = 1; k < i; ++k)
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);

                // Cắt ngang: chia hình chữ nhật i x j thành hai hình (i x k) và (i x (j-k))
                for (int k = 1; k < j; ++k)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }

    // In ra kết quả: số lần cắt tối thiểu để chia a x b thành các hình vuông
    cout << dp[a][b] << '\n';
    return 0;
}
