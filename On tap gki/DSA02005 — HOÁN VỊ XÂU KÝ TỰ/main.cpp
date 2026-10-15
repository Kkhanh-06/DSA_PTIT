#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        do {
            for (char i: s) cout << i;
            cout << " ";
        } while (next_permutation(s.begin(), s.end()));
        cout << '\n';
    }
}