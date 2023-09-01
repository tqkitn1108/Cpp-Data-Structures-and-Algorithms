// Code by Ta Quang Kien
// 28/09/2022
#include <iostream>

#define ll long long
#define FORUP(i, a, b) for (ll i = a; i <= b; ++i)
#define FORDOWN(i, a, b) for (ll i = a; i >= b; --i)
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
using namespace std;

ll Power(ll a, ll b, ll MOD) // Tính a^b %MOD
{
    ll c;
    if (b == 0)
        return 1;
    if (b == 1)
        return (a % MOD);
    c = Power(a, b / 2, MOD) % MOD;
    c = c * c % MOD;
    if (b % 2 == 1)
        c = c * a % MOD;
    return (c % MOD);
}

ll A_Module_MOD(string s, ll MOD) // Tính a% MOD
{
    ll a = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        a = a * 10 + (s[i] - 48);
        a %= MOD;
    }
    return a;
}
int Power2(ll a, string b, ll MOD) // Tính a^b % MOD với b là kiểu string
{
    ll k = a, res = 1, t;
    for (int i = b.length() - 1; i >= 0; --i)
    {
        t = Power(k, b[i] - 48, MOD);
        k = Power(k, 10, MOD);
        res = res * t % MOD;
    }
    return res;
}
int main()
{
    fast_io;
    string A, B;
    ll mod;
    cin >> A >> B >> mod;
    ll a = A_Module_MOD(A, mod);
    cout << Power2(a, B, mod);
}