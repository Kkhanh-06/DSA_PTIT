#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;  // Nhập số lượng phim

    vector<pair<ll, ll>> times;

    // Đọc thời gian bắt đầu (a) và kết thúc (b) của từng phim
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        times.push_back({b, a});  // Lưu theo thứ tự (end, start) để dễ sắp xếp theo thời gian kết thúc
    }

    // Sắp xếp các phim theo thời gian kết thúc tăng dần (greedy strategy)
    sort(times.begin(), times.end());

    ll res = 0;         // Số lượng phim có thể xem được hoàn toàn (kết quả)
    ll last_end = 0;    // Thời gian kết thúc của phim gần nhất đã chọn

    // Duyệt qua danh sách phim đã sắp xếp
    for(auto [end, start] : times){
        // Nếu thời gian bắt đầu của phim hiện tại >= thời gian kết thúc của phim trước
        // => có thể xem phim này
        if(start >= last_end){
            res++;           // Tăng số lượng phim đã chọn
            last_end = end;  // Cập nhật thời gian kết thúc gần nhất
        }
    }

    // In ra kết quả: số lượng phim có thể xem hoàn toàn
    cout << res;

    return 0;
}
