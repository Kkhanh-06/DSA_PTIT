#include <bits/stdc++.h>

using namespace std;

int main () {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (next_permutation(a.begin(), a.end())) {
            for (int i: a) {
                cout << i << " ";
            }
        } else {
            sort(a.begin(), a.end());
            for (int i: a) cout << i << " ";
        }
        cout << '\n';
    }
}