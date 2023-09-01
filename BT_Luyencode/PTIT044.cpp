// Code by Ta Quang Kien
// 28/10/2021
// U_n=5.3^n-6.2^n, n>=0
#include <iostream>
#define ll long long
const int MOD = 1e9 + 7;
using namespace std;
ll Power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = Power(a, b / 2) % MOD;
    if (b % 2 == 0)
        return (t * t) % MOD;
    else
        return (a * t * t) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a, b;
    a = (5 * Power(3, n)) % MOD;
    b = (6 * Power(2, n)) % MOD;
    cout << (a - b) % MOD;
}