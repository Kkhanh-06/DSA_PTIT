
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        int x[m + 1];

        // Khoi tao hoan vi dau tien theo thu tu giam dan
        for (int i = 1; i <= m; ++i)
            x[i] = m - i + 1;

        do {
            for (int i = 1; i <= m; ++i)
                cout << x[i];

            cout << " ";

        } while (prev_permutation(x + 1, x + m + 1));

        cout << '\n';
    }

    return 0;
}
