#include <bits/stdc++.h>
using namespace std;

string a, b;
int x_max, x_min, y_max, y_min;

int main() {
    cin >> a >> b;

    for (char i : a) {
        if (i == '5') {
            x_min = x_min * 10 + 5;
            x_max = x_max * 10 + 6;
        } 
        else if (i == '6') {
            x_min = x_min * 10 + 5;
            x_max = x_max * 10 + 6;
        } 
        else {
            x_min = x_min * 10 + (i - '0');
            x_max = x_max * 10 + (i - '0');
        }
    }

    for (char i : b) {
        if (i == '5' || i == '6') {
            y_min = y_min * 10 + 5;
            y_max = y_max * 10 + 6;
        } 
        else {
            y_min = y_min * 10 + (i - '0');
            y_max = y_max * 10 + (i - '0');
        }
    }

    cout << x_min + y_min << " " << x_max + y_max;

    return 0;
}