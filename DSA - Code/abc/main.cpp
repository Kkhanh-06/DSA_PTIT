#include <bits/stdc++.h>
using namespace std;

int n, K;
vector<int> a;
vector<int> current;
bool found;

// Backtracking
void Try(int pos, int sum) {
    // Nếu tổng đã bằng K
    if (sum == K) {
        cout << "[";

        for (int i = 0; i < current.size(); i++) {
            cout << current[i];

            if (i + 1 < current.size())
                cout << " ";
        }

        cout << "] ";
        found = true;
        return;
    }

    // Nếu vượt K thì dừng
    if (sum > K)
        return;

    // Thử chọn từng phần tử từ pos trở đi
    for (int i = pos; i < n; i++) {

        // Chọn a[i]
        current.push_back(a[i]);

        Try(i + 1, sum + a[i]);

        // Quay lui
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> K;

        a.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sắp xếp tăng dần
        sort(a.begin(), a.end());

        current.clear();
        found = false;

        Try(0, 0);

        if (!found)
            cout << "-1";

        cout << '\n';
    }

    return 0;
}