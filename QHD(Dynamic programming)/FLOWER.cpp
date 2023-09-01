// Code by Ta Quang Kien
#include <iostream>
using namespace std;

int main()
{
    int m, n, a[1001][1001], f[1001][1001];
    // f[i][j] là độ đẹp của bó hoa đẹp nhất mà Khăn Đỏ có thể hái khi đang ở ô (i,j)
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    f[0][1] = 0;
    for (int i = 1; i <= m; i++)
    {
        if (a[i][1] >= 0)
            f[i][1] = f[i - 1][1] + a[i][1];
        else
            f[i][1] = -1000001;
    }
    f[1][0] = 0;
    for (int j = 1; j <= n; j++)
    {
        if (a[1][j] >= 0)
            f[1][j] = f[1][j - 1] + a[1][j];
        else
            f[1][j] = -1000001;
    }
    for (int i = 2; i <= m; i++)
        for (int j = 2; j <= n; j++)
        {
            if (a[i][j] >= 0)
            {
                if (f[i - 1][j] >= f[i][j - 1])
                    f[i][j] = f[i - 1][j] + a[i][j];
                else
                    f[i][j] = f[i][j - 1] + a[i][j];
            }
            else
                f[i][j] = -1000001;
        }

    if (f[m][n] < 0)
        cout << -1;
    else
        cout << f[m][n];
}