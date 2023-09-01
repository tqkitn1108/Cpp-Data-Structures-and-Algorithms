// Code by Ta Quang Kien
#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int m, n, a[501][501], f[501];
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    f[1] = a[1][1];
    for (int j = 2; j <= n; j++)
    {
        f[j] = f[j - 1] + a[1][j];
    }
    for (int i = 2; i <= m; i++)
    {
        f[1] += a[i][1];
        for (int j = 2; j <= n; j++)
        {
            f[j] = max(f[j - 1], f[j]) + a[i][j];
        }
    }
    cout << f[n];
}