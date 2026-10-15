#include <bits/stdc++.h> // Thư viện tổng quát (dùng trong thi code)
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); // Tăng tốc độ nhập/xuất
    cin.tie(nullptr);                 // Không đồng bộ hóa cin/cout với C I/O (nhanh hơn)

    int n;
    cin >> n; // Nhập số lượng test case

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b; // Nhập số lượng đồng xu ở hai chồng a và b

        // Điều kiện cần để có thể lấy hết toàn bộ xu là:
        // 1. Tổng số xu (a + b) phải chia hết cho 3
        // 2. Không có chồng nào lớn hơn gấp đôi chồng kia (tức: min(a,b)*2 >= max(a,b))

        if(((a + b) % 3 == 0) && (min(a, b) * 2 >= max(a, b))){
            cout << "YES\n"; // Có thể lấy hết xu
        } else {
            cout << "NO\n";  // Không thể lấy hết xu
        }
    }

    return 0;
}
