#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n; // Nhập số lượng đồng xu

    vector<ll> coins(n);
    ll sum = 0;

    // Nhập giá trị của từng đồng xu và tính tổng tất cả đồng xu
    for(ll i = 0; i < n; i++){
        cin >> coins[i];
        sum += coins[i];
    }

    // Khởi tạo mảng dp với dp[x] = true nếu có thể tạo ra số tiền x
    vector<bool> dp(sum + 1);
    dp[0] = true; // Có thể tạo ra tổng 0 bằng cách không chọn đồng nào

    // Duyệt từng đồng xu
    for(ll i = 0; i < n; i++){
        // Duyệt ngược để tránh việc dùng 1 đồng xu nhiều lần
        for(ll j = sum; j >= coins[i]; j--){
            // Nếu đã có thể tạo ra j - coin, thì tạo được j bằng cách thêm coin vào
            if(dp[j - coins[i]]){
                dp[j] = true;
            }
        }
    }

    ll count_sum = 0; // Biến đếm số lượng tổng tiền khác nhau có thể tạo
    string s = "";    // Chuỗi chứa danh sách các số tiền có thể tạo

    // Duyệt từ 1 đến tổng tiền, loại trừ 0 vì đề không yêu cầu tổng bằng 0
    for(ll i = 1; i <= sum; i++){
        if(dp[i]){
            count_sum++; // Tăng số lượng tổng hợp lệ
            s += to_string(i) + " "; // Thêm tổng vào chuỗi kết quả
        }
    }

    s.pop_back(); // Xoá khoảng trắng cuối cùng để in đẹp hơn

    // In ra số lượng tổng khác nhau và danh sách các tổng đó
    cout << count_sum << "\n" << s;

    return 0;
}
