#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> lengths(n);
    // Nhập độ dài của các thanh gỗ
    for(long long i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    // Sắp xếp để tìm trung vị
    sort(lengths.begin(), lengths.end());

    // Chọn trung vị làm chiều dài chuẩn để tối thiểu hóa tổng chi phí
    long long median = lengths[n / 2];

    long long res = 0;
    // Tính tổng chi phí để đưa tất cả thanh gỗ về độ dài median
    for(long long i = 0; i < n; i++) {
        res += abs(lengths[i] - median); // Chi phí là trị tuyệt đối của hiệu
    }

    cout << res; // In ra tổng chi phí nhỏ nhất

    return 0;
}
