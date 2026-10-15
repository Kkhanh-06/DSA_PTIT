#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;
int n;
bool ok;

void Next_Bin_String (int m, int x[maxn]) {
    int i = m;
    while (i > 0 && x[i] != 0) {
        x[i] = 0;
        i--;
    }
    if (i > 0) x[i] = 1; else ok = false;
}

int main () {
    cin >> n;
    while (n--) {
        ok = true;
        int x[maxn];
        int m;
        cin >> m;
        for (int i = 1; i <= m; ++i) x[i] = 0;
        for (int i = 1; i <= m; ++i) cout << "A";
        cout << " ";

        while (ok) {
            Next_Bin_String(m, x);

            if (!ok) break;
            for (int i = 1; i <= m; ++i) {
                if (x[i] == 0) cout << "A"; else cout << "B";
            }
            cout << " ";
        }
        cout << '\n';
    }
}