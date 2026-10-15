// compile: g++ -O2 -std=gnu++17 mex_sliding.cpp -o mex_sliding
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Tăng tốc độ đọc/ghi
    cin.tie(nullptr);            // Tách cin và cout để nhanh hơn

    int n, k;
    if (!(cin >> n >> k)) return 0; // Đọc n và k, nếu lỗi thì thoát

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i]; // Đọc mảng

    // cnt[x] = số lần xuất hiện của giá trị x trong cửa sổ hiện tại
    // Chỉ cần lưu các giá trị 0..k (vì mex ≤ k+1)
    vector<int> cnt(k + 1, 0);

    // missing: tập các giá trị 0..k chưa xuất hiện trong cửa sổ hiện tại
    set<int> missing;
    for (int i = 0; i <= k; ++i) missing.insert(i);

    // --- Khởi tạo cửa sổ đầu tiên ---
    for (int i = 0; i < k; ++i) {
        if (a[i] <= k) {             // Chỉ quan tâm giá trị ≤ k
            ++cnt[a[i]];             // Tăng tần suất
            if (cnt[a[i]] == 1)      // Lần đầu xuất hiện trong cửa sổ
                missing.erase(a[i]); // Không còn thiếu -> xóa khỏi missing
        }
    }

    // In mex của cửa sổ đầu tiên (phần tử nhỏ nhất trong missing)
    cout << *missing.begin();

    // --- Trượt cửa sổ ---
    for (int i = k; i < n; ++i) {
        int outv = a[i - k];         // Phần tử bị loại khỏi cửa sổ
        if (outv <= k) {
            --cnt[outv];             // Giảm tần suất
            if (cnt[outv] == 0)      // Nếu không còn xuất hiện
                missing.insert(outv);// Thêm lại vào missing
        }

        int inv = a[i];              // Phần tử mới vào cửa sổ
        if (inv <= k) {
            ++cnt[inv];              // Tăng tần suất
            if (cnt[inv] == 1)       // Lần đầu xuất hiện
                missing.erase(inv);  // Xóa khỏi missing
        }

        // In mex hiện tại
        cout << ' ' << *missing.begin();
    }
    cout << '\n';
    return 0;
}
