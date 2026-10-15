#include <bits/stdc++.h>

using namespace std;

int main () {

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (next_permutation(s.begin(), s.end())) {
            cout << n << " ";
            for (char i: s) {
                cout << i;
            }
        } else {
            cout << n << " " << "BIGGEST";
        }
        cout << '\n';
    }
}