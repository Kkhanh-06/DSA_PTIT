#include <bits/stdc++.h>
using namespace std;

int sum(const vector<int>& nums1) {
    int res = 0;
    int currentMin = INT_MAX;
    for (int i = 0; i < nums1.size(); ++i) {
        currentMin = min(currentMin, nums1[i]);
        res += currentMin;
        if (currentMin == 0) break;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> nums(n);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        int res = sum(nums);
        for(int i = 0; i < n-1; i++){
            vector<int> nums1 =nums;
            nums1[i] += nums1[i+1];
            nums1[i+1] = 0;
            res = min(res, sum(nums1));
        }

        cout << res << "\n";
    }
    cin.get();
    return 0;
}
