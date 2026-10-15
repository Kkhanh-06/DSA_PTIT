#include <bits/stdc++.h>

using namespace std;

bool ok = true;
const int maxn = 1e5 + 5;
int n, x[maxn];

void Next_Bit_String (int m) {
    int i = m;
    while (i > 0 && x[i] != 0) {
        x[i] = 0;
        i--;
    }

    if (i > 0) x[i] = 1; else ok = false;
}

bool palindrom (int m, int a[maxn]) {
    bool check = true;
    for (int i = 1; i <= m / 2; ++i) {
        if (a[i] != a[m - i + 1]) {
            check = false;
            break;
        }
    }
    return check;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) x[i] = 0;
    for (int i = 1; i <= n; ++i) cout << x[i] << " ";
    cout << endl;
    while (ok) {
        Next_Bit_String(n);
        
        if (!ok) break;

        if (palindrom(n, x)) {
            for (int i = 1; i <= n; ++i) {
                cout << x[i] << " ";
            }
            cout << endl;
        }
    }
}
    
