// Code by Ta Quang Kien
#include <iostream>

#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define nmax 100002
using namespace std;

int main()
{
    fast_io;
    int n, m, d[nmax], h[nmax], res = -1, tmp, k, maxh = 0;
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> d[i] >> h[i];
    }
    maxh = h[1] + (d[1] - 1);
    if (d[m] != n && n - d[m] + h[m] > maxh)
        maxh = n - d[m] + h[m];
    FOR(i, 2, m)
    {
        if (h[i] >= h[i - 1])
        {
            if (d[i] - d[i - 1] < h[i] - h[i - 1])
            {
                maxh = -1;
                break;
            }
            else if (d[i] - d[i - 1] == h[i] - h[i - 1])
            {
                res = h[i];
            }
            else
            {
                tmp = h[i] - h[i - 1];
                k = d[i] - (d[i - 1] + tmp) - 1;
                res = h[i] + (k + 1) / 2;
            }
        }
        else
        {
            if (d[i] - d[i - 1] < h[i - 1] - h[i])
            {
                maxh = -1;
                break;
            }
            else if (d[i] - d[i - 1] == h[i - 1] - h[i])
            {
                res = h[i - 1];
            }
            else
            {
                tmp = h[i - 1] - h[i];
                k = (d[i] - tmp) - d[i - 1] - 1;
                res = h[i - 1] + (k + 1) / 2;
            }
        }
        if (res > maxh)
            maxh = res;
    }
    cout << maxh;
}