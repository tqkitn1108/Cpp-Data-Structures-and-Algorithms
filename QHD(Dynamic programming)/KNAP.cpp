// Code by Ta Quang Kien
// Bài toán cái túi, bài tương tự: PROJECT, CAYKHE
#include <iostream>
using namespace std;

int main()
{
    int n, M, x[5001], y[5001], f[5001][5001];
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 0;
    }
    for (int j = 1; j <= M; j++)
    {
        f[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (j >= x[i] && f[i - 1][j - x[i]] + y[i] > f[i - 1][j])
            {
                f[i][j] = f[i - 1][j - x[i]] + y[i];
            }
            else
                f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][M];
}