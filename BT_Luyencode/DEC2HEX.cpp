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

char IntChar(int n)
{
    if (n < 10)
        return n + 48;
    char c = 'A';
    return (char)(n - 10 + c);
}

void DECTOHEX(ll n)
{
    if (n == 0)
    {
        return;
    }
    DECTOHEX(n / 16);
    cout << IntChar(n % 16);
}
int main()
{
    fast_io;
    ll t, n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        DECTOHEX(n);
        cout << "\n";
        t--;
    }
}