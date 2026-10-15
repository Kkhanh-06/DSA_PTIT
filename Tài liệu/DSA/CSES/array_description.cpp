#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // prev: trạng thái tại bước trước
    // curr: trạng thái tại bước hiện tại
    vector<int> prev(m + 2, 0);
    vector<int> curr(m + 2, 0);

    // Khởi tạo cho phần tử đầu tiên
    if (arr[0] == 0) {
        // Nếu phần tử đầu chưa biết, có thể chọn từ 1 đến m
        for (int x = 1; x <= m; ++x)
            prev[x] = 1;
    } else {
        // Nếu đã biết, chỉ có đúng một giá trị
        prev[arr[0]] = 1;
    }

    // Duyệt từng phần tử từ vị trí 1 đến n-1
    for (int i = 1; i < n; ++i) {
        fill(curr.begin(), curr.end(), 0); // reset mảng curr

        for (int x = 1; x <= m; ++x) {
            // Nếu chưa biết hoặc đúng giá trị cần xét
            if (arr[i] == 0 || arr[i] == x) {
                curr[x] = ((prev[x - 1] + prev[x]) % MOD + prev[x + 1]) % MOD;
            }
        }

        prev = curr; // chuyển trạng thái curr thành prev cho vòng sau
    }

    // Tính tổng kết quả tại vị trí cuối
    int result = 0;
    for (int x = 1; x <= m; ++x)
        result = (result + prev[x]) % MOD;

    cout << result << '\n';
    return 0;
}
