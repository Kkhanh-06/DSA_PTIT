#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    set<int> alive;  // Tập hợp những người còn sống (sắp xếp tự động)
    for (int i = 1; i <= n; ++i)
        alive.insert(i);  // Ban đầu ai cũng còn sống

    auto it = alive.begin();  // Con trỏ bắt đầu từ người đầu tiên

    while (!alive.empty()) {
        // Di chuyển k bước theo chiều kim đồng hồ (vòng tròn)
        for (int i = 0; i < k; ++i) {
            ++it;  // Di chuyển sang người tiếp theo
            if (it == alive.end())
                it = alive.begin();  // Quay lại đầu nếu vượt qua người cuối
        }

        cout << *it << " ";  // In ra người bị loại
        it = alive.erase(it);  // Xóa người đó và trả về iterator tới người kế tiếp

        if (it == alive.end())
            it = alive.begin();  // Nếu hết danh sách thì quay lại đầu
    }
}
