// Code by Ta Quang Kien
// 8/12/2021
#include <iostream>
#include <algorithm>
#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
ll p[16];
void POWER16()
{
    p[0] = 1;
    FOR(i, 1, 15)
    {
        p[i] = p[i - 1] * 16;
    }
}
ll CharToInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - 48;
    return c - 55;
}
void HEXTOHDEC(string s)
{
    ll res = 0;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        res += CharToInt(s[i]) * p[s.length() - 1 - i];
    }
    cout << res << "\n";
}

int main()
{
    fast_io;
    ll t;
    string n;
    cin >> t;
    POWER16();
    while (t > 0)
    {
        cin >> n;
        HEXTOHDEC(n);
        t--;
    }
}