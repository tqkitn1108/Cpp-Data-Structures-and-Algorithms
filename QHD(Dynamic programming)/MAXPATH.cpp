// Code by Ta Quang Kien
#include <iostream>
using namespace std;
int max(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    if (a < b && b >= c)
        return b;
    return c;
}

int main()
{
    int m, n, a[101][101], f[101][101], maxS = -10001;
    //f[i][j] là tổng lớn nhất của 1 đường đi từ cột 1 đến ô (i,j)
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        f[i][1] = a[i][1];
    }
    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if (i == 1)
                f[i][j] = max(f[1][j - 1], f[1][j - 1], f[2][j - 1]) + a[i][j];
            else if (i == m)
            {
                f[i][j] = max(f[m][j - 1], f[m - 1][j - 1], f[m - 1][j - 1]) + a[i][j];
            }
            else
                f[i][j] = max(f[i - 1][j - 1], f[i][j - 1], f[i + 1][j - 1]) + a[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (f[i][n] > maxS)
            maxS = f[i][n];
    }
    cout << maxS;
}