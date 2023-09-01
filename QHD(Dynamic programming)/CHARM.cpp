// Code by Ta Quang Kien
// 26/10/2021
// Bài toán cái túi, bài tương tự: PROJECT, CAYKHE
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, M, x[3403], y[3403], f[2][13801];
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int j = 0; j <= M; j++)
    {
        f[0][j] = 0;
    }
    f[1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= M; j++)
            {
                if (j >= x[i] && f[0][j - x[i]] + y[i] > f[0][j])
                {
                    f[1][j] = f[0][j - x[i]] + y[i];
                }
                else
                    f[1][j] = f[0][j];
            }
        }
        else
        {
            for (int j = 1; j <= M; j++)
            {
                if (j >= x[i] && f[1][j - x[i]] + y[i] > f[1][j])
                {
                    f[0][j] = f[1][j - x[i]] + y[i];
                }
                else
                    f[0][j] = f[1][j];
            }
        }
    }
    cout << f[n % 2][M];
}