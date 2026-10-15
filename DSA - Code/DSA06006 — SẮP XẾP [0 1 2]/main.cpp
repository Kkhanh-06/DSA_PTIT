#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int main() {
    int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int a[maxn];
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
        cout << '\n';
    }
}