//#include <bits/stdc++.h>
#include <iostream>
#include <limits>

#define ll long long
#define FORUP(i, a, b) for (ll i = a; i <= b; ++i)
#define FORDOWN(i, a, b) for (ll i = a; i >= b; --i)
#define nmax 100005
#define oo 10000000007
#define mod 1000000007
#define reset(x) memset(x, 0, sizeof x)
#define PB(x) push_back(x)
#define F first
#define S second
#define debug(x) cout << "Loli -> " << #x << " : " << x << "\n"
#define debugAry(x, a, b, y)      \
    for (int y = a; y <= b; y++)  \
    cout << #x << "[" << y << "]" \
         << " -> " << x[y] << "\n"
#define fileNX                            \
    freopen(filename ".inp", "r", stdin); \
    freopen(filename ".out", "w", stdout);
#define fileN freopen(filename ".inp", "r", stdin);
#define fileX freopen(filename ".out", "w", stdout);
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define SZ(a) (int)a.size()
#define FOA(a, b) for (auto &a : b)
#define ALLvec(a) a.begin(), a.end()
#define AutoCinAry(a, b, x)      \
    for (int a = 1; a <= b; a++) \
        cin >> x[i];
#define dembit1(x) __builtin_popcount(x)
#define bit(x, i) ((x >> (i - 1)) & 1ll)
#define on(x, i) (x | (1ll << (i - 1)))
#define off(x, i) (x & ~(1ll << (i - 1)))
#define EX exit(0);
#define Ary(x, i, j, a) x[(i - 1) * a + j]
#define epsilon 1e-8
#define times double stime = clock();
#define gettime cerr << "Time executed: " << (clock() - stime) / CLOCKS_PER_SEC * 1000 << "ms.\n";
using namespace std;

ll mulmodu64(ll a, ll b, ll m) // Tính (a*b) % m (có trường hợp a*b bị tràn số)
{
    a %= m;
    b %= m;
    if (a == 0)
        return 0;
    if (b <= numeric_limits<ll>::max() / a) // Hàm numeric_limits<T>::max() trả về giá trị lớn nhất có thể đạt được của kiểu T
        return (a * b) % m;                 // VD: T là int thì numeric_limits<int>::max()=2147483647=2^31-1,numeric_limits<long long>::max()=2^63-1
    ll res = 0;
    while (a != 0)
    {
        if (a & 1) // <=> if(a%2==1)
        {
            res += b;
            if (res >= m)
                res -= m;
        }
        if (b >= m - b)
            b = 2 * b - m;
        else
            b *= 2;
        a >>= 1; // <=> a/=2;
    }
    return res;
}
ll Power(ll a, ll b, ll MOD)
{
    ll c;
    if (b == 0)
        return 1;
    if (b == 1)
        return (a % MOD);
    c = Power(a, b / 2, MOD) % MOD;
    c = mulmodu64(c, c, MOD);
    if (b % 2 == 1)
        c = mulmodu64(c, a, MOD);
    return (c % MOD);
}

int main()
{
    fast_io;
    ll a[nmax];
    FORUP(i, 0, 99999)
    {
        cin >> a[i];
    }
    FORUP(i, 0, 99999)
    {
        if (a[i] == 2)
        {
            cout << "1";
        }
        else
        {
            if (Power(2, a[i] - 1, a[i]) == 1)
            {
                cout << "1";
            }
            else
                cout << "0";
        }
        cout << "\n";
    }
    return 0;
}