#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 6;

int main() {
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        long long a[maxn];
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        long long sum = 0;
        for (int i = 0; i <= n - 1; ++i) sum = (sum + a[i + 1] * i) % mod;
        cout << sum << endl;
    }
}