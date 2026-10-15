#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    // Khởi tạo tập hợp đèn giao thông với hai vị trí đầu và cuối đường (0 và x)
    set<int> lights = {0, x};

    // Khởi tạo đoạn duy nhất ban đầu là độ dài toàn bộ con đường
    multiset<int> segments = {x};

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;

        // Tìm đèn giao thông bên phải gần nhất với vị trí p
        auto upper = lights.upper_bound(p);

        // Tìm đèn bên trái gần nhất (dùng prev)
        auto lower = prev(upper);

        int l = *lower, r = *upper;

        // Xoá đoạn hiện tại (giữa hai đèn l và r) khỏi tập các đoạn
        segments.erase(segments.find(r - l));

        // Thêm hai đoạn mới được chia từ đoạn cũ bởi đèn ở vị trí p
        segments.insert(p - l);
        segments.insert(r - p);

        // Chèn đèn mới vào tập đèn giao thông
        lights.insert(p);

        // In độ dài đoạn dài nhất (phần tử lớn nhất trong multiset)
        cout << *segments.rbegin() << ' ';
    }

    cout << '\n';
    return 0;
}
