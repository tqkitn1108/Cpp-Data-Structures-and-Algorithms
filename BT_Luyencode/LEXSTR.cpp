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

int main()
{
    fast_io;
    int n, f[123];
    cin >> n;
    string s;
    cin >> s;
    FOR(i, 'a', 'z')
    {
        cin >> f[i];
    }
    FOR(i, 0, s.length() - 1)
    {
        if (s[i] != '?')
            f[(int)s[i]]--;
    }
    FOR(i, 0, s.length() - 1)
    {
        if (s[i] == '?')
        {
            FOR(j, 'a', 'z')
            {
                if (f[j] > 0)
                {
                    s[i] = (char)j;
                    f[j]--;
                    break;
                }
            }
        }
    }
    FOR(i, 'a', 'z')
    {
        if (f[i] > 0)
        {
            cout << -1;
            return 0;
        }
    }
    cout << s;
}