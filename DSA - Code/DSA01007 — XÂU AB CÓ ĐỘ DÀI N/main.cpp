#include <bits/stdc++.h>

using namespace std;

bool ok;
const int maxn = 1e5 + 5;
int n;

void Next_Bin_String (int m, int x[maxn]) {
    int i = m;
    while (i > 0 && x[i] != 0) {
        x[i] = 0;
        i--;
    }
    if (i > 0) x[i] = 1; else ok = false;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ok = true;
        int x[maxn];
        for (int i = 1; i <= n; ++i) x[i] = 0;
        for (int i = 1; i <= n; ++i) if (x[i] == 0) cout << "A";
        cout << " ";
        while (ok) {
            Next_Bin_String(n, x);

            if (!ok) break;

            for (int i = 1; i <= n; ++i) {
                if (x[i] == 0) {
                    cout << "A";
                } else {
                    cout << "B";
                }
            }
            cout << " ";
        }
        cout << '\n';
    }
    return 0;
}