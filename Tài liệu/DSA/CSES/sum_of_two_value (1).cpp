#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;  // Nhập số phần tử của mảng và tổng cần tìm

    vector<int> a(n);  // Mảng chứa các số nguyên
    map<int, int> mp; // Map lưu các giá trị đã duyệt: value -> vị trí 1-based

    // Nhập các phần tử của mảng
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Duyệt từng phần tử để tìm cặp có tổng bằng x
    for (int i = 0; i < n; ++i) {
        int need = x - a[i];  // Tìm giá trị cần thiết để đạt tổng x

        if (mp.count(need)) {
            // Nếu đã từng gặp giá trị 'need' trước đó (trong mp)
            // Thì a[i] + need = x ⇒ in ra vị trí của hai số (1-based index)
            cout << mp[need] << " " << i + 1 << "\n";
            return 0;  // Thoát chương trình vì đã tìm được cặp hợp lệ
        }

        // Nếu chưa tìm được cặp, lưu giá trị hiện tại vào map
        // key: a[i], value: vị trí (1-based index)
        mp[a[i]] = i + 1;
    }

    // Nếu không tìm được cặp nào thỏa mãn tổng bằng x
    cout << "IMPOSSIBLE\n";
    return 0;
}
