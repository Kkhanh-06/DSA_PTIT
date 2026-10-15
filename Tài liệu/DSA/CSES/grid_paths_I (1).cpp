#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MOD = 1e9+7; // Modulo để tránh tràn số nguyên

int main() {
    int n;
    cin >> n; // Nhập kích thước ma trận n x n

    // Khởi tạo bảng dp: dp[i][j] là số cách đi đến ô (i, j)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Nhập ma trận lưới (gồm các ký tự '.' là ô trống và '*' là chướng ngại vật)
    vector<vector<char>> matrix(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    // Nếu ô xuất phát không phải chướng ngại, có đúng 1 cách đứng tại đó
    if(matrix[0][0] != '*') dp[0][0] = 1;

    // Duyệt qua từng ô trong ma trận
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == '*') continue; // Nếu là chướng ngại thì bỏ qua

            // Nếu ô phía trên tồn tại, cộng số cách từ trên xuống
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

            // Nếu ô bên trái tồn tại, cộng số cách từ trái sang
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    // In ra số cách đi từ (0,0) đến (n-1,n-1)
    cout << dp[n - 1][n - 1];
    return 0;
}
