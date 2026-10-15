#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, m;
    cin >> n >> m;

    multiset<ll> tickets; // multiset để lưu giá vé (có thể trùng nhau, và tự sắp xếp)

    // Nhập danh sách giá vé
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        tickets.insert(x); // chèn giá vé vào multiset (O(log n))
    }

    // Xử lý m người mua vé
    for(ll i = 0; i < m; i++){
        ll x;
        cin >> x; // Số tiền người i có

        // Tìm phần tử đầu tiên > x
        auto it = tickets.upper_bound(x);

        if(it == tickets.begin()){
            // Nếu không có vé nào ≤ x → không mua được
            cout << -1 << "\n";
        }
        else {
            --it; // Giảm iterator để lấy phần tử ≤ x
            cout << *it << "\n"; // In giá vé phù hợp nhất
            tickets.erase(it);   // Xoá vé đã bán khỏi multiset (O(log n))
        }
    }

    return 0;
}
