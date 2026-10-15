#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    if (k == 0) { cout << 1 << endl; return 0; }

    // dp[i][j] = number of increasing subsequences of length j ending at index i
    vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(k+1, 0));

    for (int i = 0; i < n; i++) dp[i][1] = 1;

    for (int i = 0; i < n; i++){
        for (int t = 0; t < i; t++){
            if (a[t] < a[i]){
                for (int j = 2; j <= k; j++){
                    dp[i][j] += dp[t][j-1];
                }
            }
        }
    }

    unsigned long long ans = 0;
    for (int i = 0; i < n; i++) ans += dp[i][k];

    cout << ans << endl;
    return 0;
}