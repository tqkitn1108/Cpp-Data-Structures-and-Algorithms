// Code by Ta Quang Kien
// 10/11/2021
#include <iostream>
#include <algorithm>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie();                   \
    cout.tie();
using namespace std;

int main()
{
    fast_io;
    string s;
    int m, a[100002], b[100002];
    cin >> s;
    cin >> m;
    FOR(i, 1, m)
    {
        cin >> a[i];
    }
    int len = s.length();
    sort(a + 1, a + m + 1);
    int t = 1, k = 1;
    a[m + 1] = 1000000;
    b[1] = 0;
    FOR(i, 1, m)
    {
        if (a[i] == a[i + 1])
        {
            k++;
        }
        else
        {
            if (k % 2 == 1)
            {
                b[t++] = a[i];
            }
            k = 1;
        }
    }
    if (b[1] == 0)
    {
        cout << s;
        return 0;
    }
    for (int i = 1; i <= t - 2; i += 2)
    {
        FOR(j, b[i] - 1, b[i + 1] - 2)
        {
            swap(s[j], s[len - j - 1]);
        }
    }
    if (t % 2 == 0)
    {
        int x = b[t - 1] - 1, y = len - b[t - 1];
        while (x < y)
        {
            swap(s[x], s[y]);
            x++;
            y--;
        }
    }
    cout << s;
}