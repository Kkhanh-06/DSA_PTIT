#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Hàm tính edit distance giữa 2 chuỗi s1 và s2
int edit_distance(const string& s1, const string& s2) {
    int n = s1.length(), m = s2.length();

    // Tạo bảng DP kích thước (n+1) x (m+1)
    // dp[i][j] là số thao tác tối thiểu để biến s1[0..i-1] thành s2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Khởi tạo hàng và cột đầu tiên:
    // Nếu một chuỗi là rỗng, thì ta cần chèn hoặc xoá toàn bộ ký tự của chuỗi còn lại
    for (int i = 0; i <= n; ++i)
        dp[i][0] = i; // Xoá i ký tự để biến s1[0..i-1] thành chuỗi rỗng

    for (int j = 0; j <= m; ++j)
        dp[0][j] = j; // Chèn j ký tự để biến chuỗi rỗng thành s2[0..j-1]

    // Duyệt từng cặp chỉ số i, j để điền bảng dp
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                // Nếu 2 ký tự giống nhau → không cần làm gì, lấy giá trị từ dp[i-1][j-1]
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Nếu khác nhau, chọn thao tác ít nhất trong 3:
                // - Xoá s1[i-1] → dp[i-1][j]
                // - Chèn s2[j-1] → dp[i][j-1]
                // - Thay thế s1[i-1] bằng s2[j-1] → dp[i-1][j-1]
                dp[i][j] = 1 + min({
                    dp[i - 1][j],    // Xoá
                    dp[i][j - 1],    // Chèn
                    dp[i - 1][j - 1] // Thay thế
                });
            }
        }
    }

    // Kết quả là số thao tác tối thiểu để biến toàn bộ s1 thành s2
    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;  // Nhập 2 chuỗi cần tính edit distance

    // In ra kết quả
    cout << edit_distance(s1, s2) << '\n';

    return 0;
}
