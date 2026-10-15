#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;

        while(a.size() != 1){
            int s = 0;
            for(char i : a){
                s += i-'0';
            }
            a = to_string(s);
        }
        cout << a << "\n";
    }

    return 0;
}
