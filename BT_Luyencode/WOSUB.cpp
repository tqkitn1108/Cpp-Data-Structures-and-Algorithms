// Code by Ta Quang Kien
// 24/8/2021
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a[100001], s, sum, res = -1, j;
    long long pf_sum[100001];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    pf_sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pf_sum[i] = pf_sum[i - 1] + a[i];
    }
    j = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = pf_sum[i] - pf_sum[j];
        if (sum == s)
        {
            if (i - j > res)
                res = i - j;
        }
        else if (sum > s)
        {
            while (sum > s)
            {
                j++;
                sum = pf_sum[i] - pf_sum[j];
            }
            if (sum == s)
            {
                if (i - j > res)
                    res = i - j;
            }
        }
    }
    cout << res;
}