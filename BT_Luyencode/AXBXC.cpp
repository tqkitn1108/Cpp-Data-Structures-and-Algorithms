// Code by Ta Quang Kien
// 26/10/2021
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, res = 0, a, b, c;
    cin >> k;
    if (k == 0)
        cout << res;
    else
    {
        for (int i = 1; i <= k; ++i)
        {
            a = i;
            for (int j = 1; j <= min(k / a, a); ++j)
            {
                b = j;
                for (int t = 1; t <= min(k / (a * b), b); ++t)
                {
                    c = t;
                    if (a == b && a == c)
                        res += 1;
                    else if (a == b || b == c)
                        res += 3;
                    else
                        res += 6;
                }
            }
        }
    }
    cout << res;
}