#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;  // Nhập số lượng khối

    multiset<int> towers;  // Dùng multiset để lưu đỉnh các tháp (có thể trùng nhau)

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;  // Nhập kích thước của khối thứ i

        // Tìm tháp hiện tại có đỉnh > x (nơi x có thể đặt vào)
        auto it = towers.upper_bound(x);

        if (it != towers.end()) {
            towers.erase(it);  // Nếu tìm được, xóa đỉnh cũ vì x sẽ thay thế làm đỉnh mới
        }

        towers.insert(x);  // Thêm x vào multiset làm đỉnh của 1 tháp (mới hoặc vừa được cập nhật)
    }

    // In ra số tháp đang có (tương đương với số đỉnh trong multiset)
    cout << towers.size() << endl;

    return 0;
}
