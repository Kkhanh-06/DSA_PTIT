#include <bits/stdc++.h> 

using namespace std;

const int maxn = 1e3 + 5;
bool ok = true;
int n, x[maxn];
string s;

void Next_Bit_String (int m) {
    int i = m;
    while (i > 0 && x[i] != 0) { x[i] = 0; i--; }
    if (i > 0) x[i] = 1; else ok = false;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int i = 0; i < s.length(); ++i) {
            x[i + 1] = s[i] - '0';
        }

        Next_Bit_String(s.length());
        if (ok) {
            for (int i = 1; i <= s.length(); ++i) {
                cout << x[i];
            }
            cout << endl;
        } else {
            for (int i = 1; i <= s.length(); ++i) {
                cout << 0;
            }
            cout << endl;
        }
    }
}