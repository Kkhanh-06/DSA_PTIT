#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); // Tăng tốc độ I/O
    cin.tie(nullptr);                 // Không flush cout khi cin

    int n;
    cin >> n; // Số lượng khách đến

    int maxn = 0;       // Biến lưu số lượng khách tối đa tại 1 thời điểm
    int customers = 0;  // Số khách hiện tại

    vector<pair<int, int>> c; // Vector lưu các sự kiện (thời gian, +1 hoặc -1)

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;         // Nhập thời gian đến và rời của khách i
        c.push_back({a, 1});   // Khi đến: +1 khách
        c.push_back({b, -1});  // Khi rời: -1 khách
    }

    sort(c.begin(), c.end()); // Sắp xếp theo thời gian tăng dần

    // Duyệt từng mốc thời gian
    for(auto [time, i] : c){
        customers += i;             // Cập nhật số khách hiện tại
        maxn = max(maxn, customers); // Cập nhật số khách tối đa
    }

    cout << maxn; // In ra số lượng khách nhiều nhất tại một thời điểm
    return 0;
}
