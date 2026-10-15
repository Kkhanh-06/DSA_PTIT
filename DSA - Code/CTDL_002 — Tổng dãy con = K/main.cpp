#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int n, k;
int a[maxn];
vector<vector<int>> ans;

void Try(int i, int sum, vector<int>& cur) {
    if (sum == k) {
        ans.push_back(cur);
        return;
    }

    if (i > n || sum > k) {
        return;
    }

    // Chọn a[i]
    cur.push_back(a[i]);
    Try(i + 1, sum + a[i], cur);
    cur.pop_back();

    // Không chọn a[i]
    Try(i + 1, sum, cur);
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> cur;

    Try(1, 0, cur);

    // In các dãy theo thứ tự ngược lại
    for (int i = ans.size() - 1; i >= 0; --i) {
        for (int x : ans[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }

    cout << ans.size() << '\n';

    return 0;
}