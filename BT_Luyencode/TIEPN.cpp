// Code by Ta Quang Kien
// Tính n^2%1000007 với n<=10^30
#include <iostream>
#define ll long long
const ll MOD = 1000007;
using namespace std;
ll strtonum(string s, int t, int j)
{
    ll num = 0;
    for (int i = t; i < j; i++)
    {
        num = num * 10 + s[i] - 48;
    }
    return num;
}
ll POW(int t)
{
    ll k = 1;
    for (int i = 1; i <= t; i++)
    {
        k *= 10;
    }
    return k;
}

int main()
{
    string n;
    ll a, b, c;
    cin >> n;
    int len = n.length();
    if (len >= 17)
    {
        a = strtonum(n, 0, 14) % MOD;
        b = POW(len - 14) % MOD;
        c = strtonum(n, 14, len) % MOD;
        a = ((a * b) + c) % MOD;
        cout << (a * a) % MOD;
    }
    else
    {
        a = strtonum(n, 0, len) % MOD;
        cout << (a * a) % MOD;
    }
}