
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

void Next_Bin_String_Rv(int m, int a[]) {
    int i = m;

    while (i >= 1 && a[i] != 1) {
        a[i] = 1;
        i--;
    }

    if (i >= 1)
        a[i] = 0;
    else
        for (int j = 1; j <= m; j++)
            a[j] = 1;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int x[maxn] = {};

        for (int i = 0; i < (int)s.size(); i++)
            x[i + 1] = s[i] - '0';

        Next_Bin_String_Rv(s.size(), x);

        for (int i = 1; i <= (int)s.size(); i++)
            cout << x[i];

        cout << '\n';
    }

    return 0;
}
