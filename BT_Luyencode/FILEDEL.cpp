// Code by Ta Quang Kien
// 7/11/2021
#include <iostream>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool check[120];
    int n, q;
    string s[100001];
    char c[100001];
    cin >> n >> q;
    int count = n;
    FOR(i, 1, n)
    {
        cin >> s[i];
    }
    FOR(i, 1, q)
    {
        cin >> c[i];
    }
    FOR(i, 1, n)
    {
        string str = s[i];
        FOR(j, 0, str.length())
        {
            check[str[j]] = true;
        }
    }
    FOR(i, 1, q)
    {
        if (!check[c[i]])
        {
            cout << count << "\n";
        }
        else
        {
            FOR(j, 1, n)
            {
                string str = s[j];
                FOR(t, 0, str.length())
                {
                    if (str[t] == c[i])
                    {
                        s[j] = '0';
                        count--;
                        break;
                    }
                }
            }
            cout << count << "\n";
            check[c[i]] = 0;
        }
    }
}