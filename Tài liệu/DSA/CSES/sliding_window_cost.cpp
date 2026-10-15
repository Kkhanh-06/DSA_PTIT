#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Cấu trúc dữ liệu hỗ trợ:
//  - Thêm/xóa phần tử
//  - Lấy median của cửa sổ hiện tại
//  - Tính tổng khoảng cách tuyệt đối từ median đến tất cả các phần tử trong cửa sổ
struct SlidingMedianCost {
    multiset<ll> low, high;  // low: nửa nhỏ hơn hoặc bằng median, high: nửa lớn hơn median
    ll sumLow = 0, sumHigh = 0; // tổng giá trị các phần tử trong low và high

    // Thêm phần tử vào cửa sổ
    void insert(ll x) {
        // Nếu low rỗng hoặc x <= phần tử lớn nhất trong low => đưa vào low
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }
        balance(); // Cân bằng kích thước hai nửa
    }

    // Xóa phần tử ra khỏi cửa sổ
    void erase(ll x) {
        // Nếu phần tử nằm trong low
        if (low.find(x) != low.end()) {
            low.erase(low.find(x));
            sumLow -= x;
        } else { // Nằm trong high
            high.erase(high.find(x));
            sumHigh -= x;
        }
        balance(); // Cân bằng lại
    }

    // Đảm bảo kích thước low >= high và chênh lệch tối đa 1
    void balance() {
        // Nếu low quá nhiều phần tử
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end()); // phần tử lớn nhất của low
            ll val = *it;
            low.erase(it);
            sumLow -= val;
            high.insert(val);
            sumHigh += val;
        }
        // Nếu high có nhiều hơn low
        while (low.size() < high.size()) {
            auto it = high.begin(); // phần tử nhỏ nhất của high
            ll val = *it;
            high.erase(it);
            sumHigh -= val;
            low.insert(val);
            sumLow += val;
        }
    }

    // Lấy median (phần tử lớn nhất của low)
    ll getMedian() {
        return *low.rbegin();
    }

    // Tính tổng chi phí: sum(|a[i] - median|)
    ll getCost() {
        ll m = getMedian();
        // Khoảng cách từ median tới các phần tử trong low
        ll costLow = m * (ll)low.size() - sumLow;
        // Khoảng cách từ median tới các phần tử trong high
        ll costHigh = sumHigh - m * (ll)high.size();
        return costLow + costHigh;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SlidingMedianCost smc;

    // Khởi tạo cửa sổ đầu tiên
    for (int i = 0; i < k; i++) smc.insert(a[i]);
    cout << smc.getCost();

    // Trượt cửa sổ
    for (int i = k; i < n; i++) {
        smc.insert(a[i]);        // thêm phần tử mới
        smc.erase(a[i - k]);     // xóa phần tử cũ
        cout << " " << smc.getCost();
    }
    cout << "\n";
}
