#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k; // Nhập số phần tử mảng n và kích thước cửa sổ k
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; // Nhập mảng a

    unordered_map<int, int> freq; // Bảng đếm tần suất của các phần tử trong cửa sổ
    freq.reserve(k * 2);          // Dự trữ dung lượng để giảm số lần rehash
    freq.max_load_factor(0.7);    // Giảm hệ số tải để tăng tốc độ

    // Khởi tạo cửa sổ đầu tiên (tính tần suất k phần tử đầu)
    for (int i = 0; i < k; i++) {
        freq[a[i]]++;
    }
    cout << freq.size(); // In số lượng phần tử khác nhau trong cửa sổ đầu

    // Trượt cửa sổ từ vị trí k đến n-1
    for (int i = k; i < n; i++) {
        // Giảm tần suất của phần tử bị loại khỏi cửa sổ
        if (--freq[a[i - k]] == 0)
            freq.erase(a[i - k]); // Nếu tần suất về 0 thì xóa khỏi map

        // Thêm phần tử mới vào cửa sổ
        freq[a[i]]++;

        // In số phần tử khác nhau trong cửa sổ hiện tại
        cout << " " << freq.size();
    }
    cout << "\n"; // Xuống dòng sau khi in xong
}
