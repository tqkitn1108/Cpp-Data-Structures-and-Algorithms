// Code by Ta Quang Kien
// 11/12/2021
// Chuyển nhị phân sang thập phân
#include <iostream>
#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

ll p[63];
void POWER2()
{
    p[0] = 1;
    FOR(i, 1, 62)
    {
        p[i] = p[i - 1] * 2;
    }
}
void BINTODEC(string s)
{
    ll res = 0, len = s.length();
    FOR(i, 0, len - 1)
    {
        if (s[i] == '1')
            res += p[len - 1 - i];
    }
    cout << res << "\n";
}
int main()
{
    int t;
    string s;
    cin >> t;
    while (t > 0)
    {
        cin >> s;
        POWER2();
        BINTODEC(s);
        t--;
    }
}