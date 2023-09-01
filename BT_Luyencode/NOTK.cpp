// Code by Ta Quang Kien
// 6/12/2021
#include <iostream>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();

using namespace std;

int main()
{
    fast_io;
    int n, a[200001], b[200001] = {}, cnt = 0;
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    FOR(i, 1, n)
    {
        b[a[i]]++;
    }
    FOR(i, 1, n)
    {
        if (b[a[i]] != 0)
        {
            cnt += b[a[i]] * (b[a[i]] - 1) / 2;
        }
        b[a[i]] = 0;
    }
    FOR(i, 1, n)
    {
        b[a[i]]++;
    }
    FOR(i, 1, n)
    {
        cout << cnt + 1 - b[a[i]] << "\n";
    }
}