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
char IntChar(int n)
{
    if (n < 10)
        return n + 48;
    char c = 'A';
    return (char)(n - 10 + c);
}
void BINTOHEX(string s)
{
    while (s.length() % 4 != 0)
        s = '0' + s;
    string res = "";
    ll temp = 0;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        if (s[i] == '1')
            temp += p[(s.length() - 1 - i) % 4];
        if (i % 4 == 0)
        {
            res = IntChar(temp) + res;
            temp = 0;
        }
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
        BINTOHEX(n);
        t--;
    }
}