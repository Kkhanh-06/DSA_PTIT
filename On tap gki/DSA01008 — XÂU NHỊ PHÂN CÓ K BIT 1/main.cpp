#include <bits/stdc++.h>

using namespace std;

bool ok;

void Next_Bin_String (int m, int a[]) {
    int i = m;
    while (i > 0 && a[i] != 0) {
        a[i] = 0;
        i--;
    }
    if (i > 0) a[i] = 1; else ok = false;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= n; ++i) a[i] = 0;
        ok = true;
        while (ok) {
            Next_Bin_String(n, a);

            if (count(a + 1, a + n + 1, 1) == k) {
                for (int i = 1; i <= n; ++i) cout << a[i];
                cout << '\n';
            }
        }
    }
}