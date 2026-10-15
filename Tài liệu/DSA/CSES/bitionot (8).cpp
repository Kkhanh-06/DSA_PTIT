#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int n, i = 5, s = 0;
    cin >> n;

    while(n >= i){
        s += n / i;
        i*=5;
    }
    cout << s;
    return 0;
}
