#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Lưu các đoạn [a, b] cùng với chỉ số ban đầu (để in ra theo đúng thứ tự đầu vào)
    vector<tuple<int, int, int>> ranges; // (start, end, original_index)

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ranges.emplace_back(a, b, i); // Thêm đoạn vào danh sách
    }

    // Sắp xếp các đoạn theo:
    // - a tăng dần (bắt đầu càng nhỏ càng đứng trước)
    // - nếu a bằng nhau thì b giảm dần (kết thúc càng lớn càng đứng trước)
    sort(ranges.begin(), ranges.end(), [](auto &x, auto &y) {
        if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
        return get<1>(x) > get<1>(y);
    });

    // contains[i] = 1 nếu đoạn i chứa ít nhất một đoạn khác
    // contained[i] = 1 nếu đoạn i bị chứa bởi ít nhất một đoạn khác
    vector<int> contains(n), contained(n);

    // Tìm các đoạn bị chứa: duyệt từ trái qua phải
    int max_end = 0; // max_end lưu giá trị kết thúc lớn nhất đã gặp
    for (auto &[a, b, idx] : ranges) {
        if (b <= max_end) 
            contained[idx] = 1; // đoạn hiện tại bị chứa trong đoạn trước
        max_end = max(max_end, b); // cập nhật đoạn kết thúc lớn nhất
    }

    // Tìm các đoạn chứa người khác: duyệt từ phải qua trái
    int min_end = 2e9; // min_end lưu kết thúc nhỏ nhất phía sau
    for (int i = n - 1; i >= 0; --i) {
        auto &[a, b, idx] = ranges[i];
        if (b >= min_end) 
            contains[idx] = 1; // đoạn hiện tại chứa ít nhất một đoạn phía sau
        min_end = min(min_end, b); // cập nhật giá trị kết thúc nhỏ nhất
    }

    // In kết quả: contains
    for (int x : contains) cout << x << ' ';
    cout << '\n';

    // In kết quả: contained
    for (int x : contained) cout << x << ' ';
    cout << '\n';

    return 0;
}
