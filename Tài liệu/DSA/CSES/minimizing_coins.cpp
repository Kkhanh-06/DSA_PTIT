#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7; // Giá trị lớn để đại diện cho "vô cực" (vì không có số âm)

int main(){
    int n, x;
    cin >> n >> x; // n: số loại đồng xu, x: số tiền cần đạt được

    vector<int> dp(x+1, MOD); // dp[i]: số lượng đồng xu tối thiểu để tạo ra số tiền i
    vector<int> money(n);     // money[i]: mệnh giá của đồng xu thứ i

    dp[0] = 0; // Không cần đồng xu nào để tạo ra số tiền 0

    // Nhập mệnh giá từng đồng xu
    for(int i = 0; i < n; i++){
        cin >> money[i];
    }

    // Tính dp[i] cho từng số tiền từ 1 đến x
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i >= money[j]){
                // Nếu mệnh giá money[j] có thể dùng để tạo ra số tiền i
                // thì cập nhật dp[i] bằng cách chọn ít đồng xu hơn
                dp[i] = min(dp[i], dp[i - money[j]] + 1);
            }
        }
    }

    // Nếu không có cách nào tạo ra số tiền x thì in -1
    if(dp[x] == MOD) cout << -1;
    else cout << dp[x]; // In ra số đồng xu ít nhất để tạo được x

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