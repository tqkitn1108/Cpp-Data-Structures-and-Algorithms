// Code by Ta Quang Kien
// 14/11/2021
#include <iostream>
#include <cmath>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie();                   \
    cout.tie();
using namespace std;

int main()
{
    fast_io;
    int a[10], temp;
    a[0] = 0;
    FOR(i, 1, 8)
    {
        a[i] = i * 9 * pow(10, i - 1) + a[i - 1];
    }
    a[9] = 1000000000;
    int k;
    while (cin >> k)
    {
        FOR(i, 1, 9)
        {
            if (k <= a[i])
            {
                temp = i;
                break;
            }
        }
        k -= a[temp - 1];
        int b = (k / temp) - 1 + pow(10, temp - 1);
        int r = k % temp;
        if (r == 0)
            cout << b % 10 << "\n";
        else
        {
            b = (b + 1) / pow(10, temp - r);
            cout << b % 10 << "\n";
        }
    }
}