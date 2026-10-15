#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7; // Sử dụng modulo để tránh tràn số nguyên

int main(){
    int n, x;
    cin >> n >> x; // Nhập số lượng loại đồng xu và tổng cần tạo

    vector<int> money(n); // Mảng lưu giá trị từng loại đồng xu
    vector<int> dp(x+1, 0); // dp[i] là số cách để tạo ra tổng i
    dp[0] = 1; // Có đúng 1 cách để tạo ra tổng 0: không dùng đồng xu nào

    // Nhập giá trị từng loại đồng xu
    for(int i = 0; i < n; i++){
        cin >> money[i];
    }

    // Duyệt qua từng tổng i từ 1 đến x
    for(int i = 1; i <= x; i++){
        // Duyệt qua từng loại đồng xu
        for(int j = 0; j < n; j++){
            if(i >= money[j]) {
                // Nếu có thể dùng đồng xu này, thì cộng thêm số cách tạo tổng (i - money[j])
                dp[i] = (dp[i] + dp[i - money[j]]) % MOD;
            }
        }
    }

    cout << dp[x]; // In ra số cách tạo tổng x
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