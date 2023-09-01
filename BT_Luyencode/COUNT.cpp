// Code by Ta Quang Kien
// 13/10/2021
#include <iostream>
#define ll long long
#define nmax 500001
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    ll n, res = 0, i, cnt = 0;
    ll *w = new ll[nmax], *prf_sum = new ll[nmax];
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> w[i];
    }
    prf_sum[0] = 0;
    for (i = 1; i <= n; ++i)
    {
        prf_sum[i] = prf_sum[i - 1] + w[i];
    }
    if (prf_sum[n] % 3 == 0)
    {
        int temp = prf_sum[n] / 3;
        for (i = 1; i < n - 1; ++i)
        {
            if (prf_sum[i] == temp)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if (prf_sum[j] - prf_sum[i] == temp)
                        res += cnt + 1;
                    if (prf_sum[j] - prf_sum[i] == 0)
                        cnt++;
                }
                break;
            }
        }
    }
    cout << res;
}