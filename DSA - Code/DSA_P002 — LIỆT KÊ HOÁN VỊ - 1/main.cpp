#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

bool ok = true;
int n, x[maxn];

void Next_Permutation(int m) {
    // Bước 1: Tìm vị trí j lớn nhất sao cho x[j] < x[j + 1]
    int j = m - 1;

    while (j > 0 && x[j] > x[j + 1]) {
        j--;
    }

    // Không còn hoán vị kế tiếp
    if (j == 0) {
        ok = false;
        return;
    }

    // Bước 2: Tìm x[k] nhỏ nhất nhưng lớn hơn x[j]
    int k = m;

    while (x[j] > x[k]) {
        k--;
    }

    // Đổi x[j] và x[k]
    int t = x[j];
    x[j] = x[k];
    x[k] = t;

    // Bước 3: Đảo ngược đoạn phía sau
    int r = j + 1;
    int s = m;

    while (r < s) {
        t = x[r];
        x[r] = x[s];
        x[s] = t;

        r++;
        s--;
    }
}

int main() {
    cin >> n;

    // Hoán vị đầu tiên: 1 2 3 ... n
    for (int i = 1; i <= n; ++i) {
        x[i] = i;
    }

    // Sinh tất cả hoán vị
    int count = 1;
    while (ok) {
        cout << count << ": ";
        for (int i = 1; i <= n; ++i) {
            cout << x[i] << " ";
        }
        cout << '\n';
        
        count++;
        Next_Permutation(n);
    }

    return 0;
}