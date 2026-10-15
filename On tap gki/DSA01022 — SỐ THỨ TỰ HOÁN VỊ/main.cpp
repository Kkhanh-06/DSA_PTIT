#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> x(n);
        int all = 1;
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            all *= i + 1;
        }
        int dem = 0;
        while (next_permutation(x.begin(), x.end())) {
            ++dem;
        }
        cout << all - dem << '\n';
    }
}