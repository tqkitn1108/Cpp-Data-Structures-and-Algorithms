// Code by Ta Quang Kien
#include <iostream>
#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FOR(i, a, b) for (int i = a; i <= b; ++i)

using namespace std;
ll t, n[1001], res;
ll *f = new ll[1000001];
int A(ll k)
{
    ll tmp = k;
    while (3 * tmp + 1 > 1000000)
    {
        if (tmp % 2 == 0)
        {
            tmp /= 2;
        }
        else
            tmp = tmp * 3 + 1;
        res++;
    }
    return tmp;
}
int main()
{
    fast_io;
    cin >> t;
    FOR(i, 1, t)
    {
        cin >> n[i];
    }
    FOR(i, 2, 1000000)
    {
        if (i % 2 == 0)
        {
            f[i] = i / 2;
        }
        else
            f[i] = 3 * i + 1;
    }
    FOR(i, 1, t)
    {
        res = 0;
        ll temp = n[i];
        if (temp != 1)
        {
            res = 1;
            while (f[temp] != 1)
            {
                temp = f[temp];
                if (temp > 1000000)
                {
                    temp=A(temp);
                }
                res++;
            }
        }
        cout << res << "\n";
    }
}