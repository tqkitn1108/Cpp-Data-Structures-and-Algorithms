// Code by Ta Quang Kien
#include <iostream>
using namespace std;
long long power(int n)
{
    int t = 1;
    for (int i = 1; i <= n; i++)
    {
        t *= 2;
    }
    return t;
}

int main()
{
    int n, m, a[100001], b[100001];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    long long X = 0;
    for (int i = 1; i <= m; i++)
    {
        int l = 1, r = n, idx, res = 0;
        while (l <= r)
        {
            idx = (l + r) / 2;
            if (b[i] == a[idx])
            {
                r = idx;
                res = idx;
                if (l == r)
                    break;
            }
            if (b[i] > a[idx])
            {
                l = idx + 1;
            }
            if (b[i] < a[idx])
            {
                r = idx - 1;
            }
        }
        if (res == 0)
            X -= 1;
        else
            X += res;
    }
    if (X == 0)
        cout << 1;
    else if (X < 0)
    {
        cout << 0;
    }
    else
    {
        X = X % 30;
        cout << power(X);
    }
}