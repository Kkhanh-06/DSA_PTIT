#include <bits/stdc++.h>

using namespace std;

int x[20], n, k;
int dem = 0;

void Result() {
    cout << dem << ": ";
    for (int i = 1; i <= k; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool isPrime() {
    if (dem < 2) return false;
    for (int i = 2; i <= int (sqrt(dem)); ++i) {
        if (dem % i == 0) return false;
    }
    return dem > 1;
}  

void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; ++j) {
        x[i] = j;
        if (i == k) {
            ++dem;
            if (isPrime()) Result();
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    Try(1);
}