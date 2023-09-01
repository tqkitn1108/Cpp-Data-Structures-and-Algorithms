// Code by Ta Quang Kien
// 11/12/2021
#include <iostream>
#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
ll p[4] = {1, 2, 4, 8};
ll CharToInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - 48;
    return c - 55;
}
void HEXTOBIN(string s)
{
    string res = "";
    FOR(i, 0, s.length() - 1)
    {
        ll temp = CharToInt(s[i]);
        for (int j = 3; j >= 0; --j)
        {
            if (temp >= p[j])
            {
                res += '1';
                temp -= p[j];
            }
            else
                res += '0';
        }
    }
    while (res[0] == '0')
    {
        res.erase(0, 1);
    }
    cout << res << "\n";
}

int main()
{
    fast_io;
    ll t;
    string n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        HEXTOBIN(n);
        t--;
    }
}