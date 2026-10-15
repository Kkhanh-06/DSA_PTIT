#include <bits/stdc++.h>

using namespace std;

bool ok = true;
int n;
const int maxn = 1e3 + 5;

void Next_Bin_String (int m, int a[maxn]) {
    int i = m;
    while (i > 0 && a[i] != 0) {
        a[i] = 0;
        i--;
    }
    if (i > 0) a[i] = 1; else ok = false;
}

int main () {
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int x[maxn], m = s.size();
        for (int i = 0; i < s.size(); ++i) {
            x[i + 1] = s[i] - '0';
        }
        if (ok) {
            Next_Bin_String(m, x);
            for (int i = 1; i <= m; ++i) cout << x[i];
            cout << '\n';
        } else {
            for (int i = 1; i <= m; ++i) cout << 0;
            cout << '\n';
        }
    }
}