#include <iostream>
#include <vector>
#include <climits> // Để dùng INT_MAX
using namespace std;

// Hàm tách các chữ số của một số nguyên thành mảng
vector<int> splitDigit(int n) {
    vector<int> digit;
    while (n > 0) {
        digit.push_back(n % 10); // Lấy chữ số cuối cùng
        n /= 10;                 // Bỏ chữ số cuối
    }
    return digit; // Trả về mảng chữ số (theo thứ tự ngược)
}

int main() {
    int n;
    cin >> n; // Nhập số nguyên n

    // dp[i] là số bước tối thiểu để giảm số i về 0 bằng cách trừ đi một chữ số của nó
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; // Cơ sở: 0 cần 0 bước

    // Tính dp[i] cho tất cả i từ 1 đến n
    for (int i = 1; i <= n; i++) {
        vector<int> digits = splitDigit(i); // Lấy các chữ số của i

        for (int d : digits) {
            if (d == 0) continue; // Bỏ qua chữ số 0 (không thể trừ)
            // Nếu trừ được d, thì xét số bước cần để đi từ (i - d) → i
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }

    cout << dp[n]; // In ra số bước tối thiểu để giảm n về 0
    return 0;
}
