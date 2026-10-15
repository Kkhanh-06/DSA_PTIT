#include <bits/stdc++.h>
using namespace std;

int a[20];
int b[20][100], dem = 0;
int x[20][20];

bool Ok(int x2, int y2)
{
    for (int i = 1; i < x2; ++i)
    {
        if (a[i] == y2 || abs(i - x2) == abs(a[i] - y2))
            return false;
    }
    return true;
}

void Try(int i, int n)
{
    for (int j = 1; j <= n; ++j)
    {
        if (Ok(i, j))
        {
            a[i] = j;
            if (i == n)
            {
                dem++;
                for (int k = 1; k <= n; ++k)
                    b[k][dem] = a[k];
            }
            else
            {
                Try(i + 1, n);
            }
        }
    }
}

int main()
{
    Try(1, 8);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        for (int i = 1; i <= 8; ++i)
            for (int j = 1; j <= 8; ++j)
                cin >> x[i][j];

        int maxx = INT_MIN;
        for (int i = 1; i <= dem; ++i)
        {
            int sum = 0;
            for (int j = 1; j <= 8; ++j)
                sum += x[j][b[j][i]];
            maxx = max(maxx, sum);
        }
        cout << " Test " << tc << ": " << maxx << "\n";
    }
}