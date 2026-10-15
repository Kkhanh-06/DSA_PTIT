#include <bits/stdc++.h>

using namespace std;

bool ok;

void Next_Num (int n, int k, int a[]) {
    int i = k;
    while (i >= 1 && a[i] == n - k + i) {
        i--;
    }

    if (i == 0) {
        ok = false;
        return;
    }

    a[i]++;
    for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
}

int main () {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[k + 1], b[k + 1], dem = 0;
        for (int i = 1; i <= k; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }

        ok = true;
        Next_Num(n, k, a);
        if (ok) {
            for (int i = 1; i <= k; ++i) {
                if (count(a + 1, a + k + 1, b[i]) == 0) dem++;
            }
        } else {
            dem = k;
        }
        cout << dem << '\n';
    }
}