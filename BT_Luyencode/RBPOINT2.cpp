// Code by Ta Quang Kien
#include <iostream>
#include <algorithm>
#define nmax 100002
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, b[nmax], r[nmax], i, res = 999999999;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (i = 1; i <= n; ++i)
    {
        cin >> r[i];
    }
    sort(b + 1, b + n + 1);
    sort(r + 1, r + n + 1);
    int j = 1, k = 1;
    while (j <= n && k <= n)
    {
        if (b[j] > r[k])
        {
            if (b[j] - r[k] < res)
                res = b[j] - r[k];
            k++;
        }
        if (b[j] <= r[k])
        {
            if (r[k] - b[j] < res)
                res = r[k] - b[j];
            j++;
        }
    }
    cout << res;
}