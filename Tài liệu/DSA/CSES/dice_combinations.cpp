#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7; // Modulo để tránh tràn số khi tính toán số tổ hợp lớn

int main(){
    int n;
    cin >> n; // Nhập tổng cần đạt được bằng cách tung xúc xắc

    vector<int> dp(n+1, 0); // dp[i] lưu số cách để tạo ra tổng i
    dp[0] = 1; // Có 1 cách để tạo tổng 0: không tung xúc xắc nào

    // Duyệt qua từng tổng từ 1 đến n
    for(int i = 1; i <= n; i++){
        // Thử tung xúc xắc ra các giá trị từ 1 đến 6
        for(int j = 1; j < 7; j++){
            if(j <= i) {
                // Nếu xúc xắc tung ra j mà j <= i, thì có thể thêm cách từ dp[i-j]
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
    }

    cout << dp[n] << std::endl; // In ra số cách để tạo tổng n
    return 0;
}


// dp[i] = giá trị tốt nhất (lớn nhất / nhỏ nhất / số cách / số bước)
//         cho bài toán với đầu vào i
// dp[i] = min / max / sum (dp[j] + chi phí từ j → i), với j < i hoặc điều kiện hợp lệ
// → Tùy bài:
//   - Bài tối ưu        → min() hoặc max()
//   - Bài đếm / tổ hợp  → cộng dồn (+)
//   - Bài có ràng buộc  → xét j theo điều kiện (vd: j ≤ i - coin[k])
// for (int i = 1; i <= N; ++i) {
//     for (int j : các trạng thái trước hoặc lựa chọn hợp lệ) {
//         // Cập nhật dp[i] từ dp[j]
//         dp[i] = min(dp[i], dp[j] + cost);
//         // hoặc dp[i] += dp[j]; // nếu là bài đếm số cách
//     }
// }
