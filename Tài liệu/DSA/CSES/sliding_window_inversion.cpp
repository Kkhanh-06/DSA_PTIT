#include <bits/stdc++.h>
using namespace std;

// Cấu trúc dữ liệu Fenwick Tree (Binary Indexed Tree)
// Dùng để:
//   - Cập nhật giá trị tại một chỉ số (update)
//   - Lấy tổng prefix (query)
//   - Tính tổng trong một khoảng (queryRange)
struct BIT {
    int n;
    vector<long long> bit;
    BIT(int n) : n(n), bit(n+1, 0) {}

    // Cập nhật giá trị tại idx (thêm delta)
    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) 
            bit[idx] += delta;
    }

    // Lấy tổng từ 1 đến idx
    long long query(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) 
            res += bit[idx];
        return res;
    }

    // Lấy tổng trong khoảng [l, r]
    long long queryRange(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // --- Nén giá trị ---
    // Để Fenwick Tree hoạt động, ta cần đánh số từ 1..m cho các giá trị
    vector<long long> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto getId = [&](long long x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };
    
    int m = vals.size();
    BIT bit(m);
    
    long long invCount = 0;      // Biến lưu số cặp nghịch thế (inversion count) trong cửa sổ
    vector<long long> result;    // Kết quả cho từng cửa sổ
    
    // --- Khởi tạo cửa sổ đầu tiên ---
    for (int i = 0; i < k; i++) {
        int id = getId(a[i]);  // Lấy chỉ số nén
        invCount += bit.queryRange(id+1, m); // Đếm phần tử lớn hơn a[i] đã xuất hiện
        bit.update(id, 1); // Đánh dấu đã thấy a[i]
    }
    result.push_back(invCount);
    
    // --- Trượt cửa sổ ---
    for (int i = k; i < n; i++) {
        // Xóa phần tử ra khỏi cửa sổ
        int outId = getId(a[i-k]);
        bit.update(outId, -1); // Xóa khỏi BIT
        invCount -= bit.queryRange(1, outId-1); // Loại bỏ số cặp (out, x) với out > x

        // Thêm phần tử mới vào cửa sổ
        int inId = getId(a[i]);
        invCount += bit.queryRange(inId+1, m); // Đếm số phần tử x > in đã có
        bit.update(inId, 1); // Đưa vào BIT
        
        result.push_back(invCount);
    }
    
    // --- Xuất kết quả ---
    for (auto x : result) cout << x << " ";
    cout << "\n";
}
