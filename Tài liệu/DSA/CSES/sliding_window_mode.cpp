#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Bảng tần suất của mỗi giá trị trong cửa sổ
    unordered_map<int,int> freq; // value -> frequency

    // set lưu các cặp (-tần suất, giá trị)
    //  Dùng tần suất âm để sắp xếp giảm dần theo tần suất
    //  Nếu tần suất bằng nhau thì sắp xếp tăng dần theo giá trị
    set<pair<int,int>> s;

    // Hàm thêm một giá trị vào cửa sổ
    auto add = [&](int val) {
        int old = freq[val];          // tần suất cũ
        if (old > 0) s.erase({-old, val}); // xóa bản ghi cũ trong set (nếu có)
        freq[val] = old + 1;          // tăng tần suất
        s.insert({-(old + 1), val});  // thêm bản ghi mới với tần suất âm
    };

    // Hàm xóa một giá trị khỏi cửa sổ
    auto remove = [&](int val) {
        int old = freq[val];          // tần suất hiện tại
        s.erase({-old, val});         // xóa bản ghi cũ
        if (old == 1) {
            // Nếu tần suất chỉ còn 1 thì xóa khỏi bảng tần suất
            freq.erase(val);
        } else {
            // Giảm tần suất xuống 1
            freq[val] = old - 1;
            s.insert({-(old - 1), val});
        }
    };

    // Khởi tạo cửa sổ đầu tiên
    for (int i = 0; i < k; i++) add(a[i]);

    // Phần tử có tần suất cao nhất trong cửa sổ hiện tại
    cout << s.begin()->second;

    // Trượt cửa sổ qua các vị trí còn lại
    for (int i = k; i < n; i++) {
        remove(a[i - k]);     // xóa phần tử rời khỏi cửa sổ
        add(a[i]);            // thêm phần tử mới vào cửa sổ
        cout << " " << s.begin()->second; // in kết quả
    }
    cout << "\n";
}
