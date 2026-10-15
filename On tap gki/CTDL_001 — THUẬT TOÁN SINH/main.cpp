#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int n, x[maxn];
bool ok = true;

void Next_Bin_String (int m) {
    int i = m;
    while (i > 0 && x[i] != 0) {
        x[i] = 0;
        i--;
    }
    if (i > 0) x[i] = 1; else ok = false;
}

bool palindrome (int m, int a[maxn]) {
    for (int i = 1; i <= m / 2; ++i) {
        if (a[i] != a[m - i + 1]) {
            return false;
            break;
        }
    }
    return true;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) x[i] = 0;
    for (int i = 1; i <= n; ++i) cout << x[i] << ' ';
    cout << '\n';

    while (ok) {
        Next_Bin_String(n);

        if (!ok) break;

        if (palindrome(n, x)) {
            for (int i = 1; i <= n; ++i) cout << x[i] << " ";
            cout << '\n';
        }
    }
}