#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    long long W;
    cin >> n >> W;

    vector<long long> c(n+1), a(n+1);
    for (int j = 1; j <= n; j++) cin >> c[j];
    for (int j = 1; j <= n; j++) cin >> a[j];

    // dp[i][w] = best value using first i items with capacity w
    vector<vector<long long>> dp(n+1, vector<long long>(W+1, 0));

    for (int i = 1; i <= n; i++){
        for (long long w = 0; w <= W; w++){
            dp[i][w] = dp[i-1][w]; // khong lay item i
            if (a[i] <= w){
                dp[i][w] = max(dp[i][w], dp[i-1][w - a[i]] + c[i]);
            }
        }
    }

    long long FOPT = dp[n][W];

    // Truy vet de tim XOPT
    vector<int> x(n+1, 0);
    long long w = W;
    for (int i = n; i >= 1; i--){
        if (dp[i][w] != dp[i-1][w]){
            x[i] = 1;
            w -= a[i];
        } else {
            x[i] = 0;
        }
    }

    cout << FOPT << "\n";
    for (int j = 1; j <= n; j++){
        cout << x[j];
        if (j < n) cout << " ";
    }
    cout << "\n";

    return 0;
}