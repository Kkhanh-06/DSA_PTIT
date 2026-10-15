#include <bits/stdc++.h>

using namespace std;

int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int t, n;
int num;

int main () {
    cin >> t;
    while (t--) {
        cin >> n;
        num = 0;
        for (int i = 9; i >= 0; --i) {
            while (n - a[i] >= 0) {
                n -= a[i];
                num++;
            }
            if (n == 0) break;
        }
        cout << num << endl;
    }
}
