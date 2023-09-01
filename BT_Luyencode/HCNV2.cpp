// Code by Ta Quang Kien
// 12/10/2021
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    ll res;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);
    if (x3 > x4)
        swap(x3, x4);
    if (y3 > y4)
        swap(y3, y4);
    if (x1 >= x4 || x2 <= x3 || y1 >= y4 || y2 <= y3)
        res = 0;
    else
    {
        res = (min(x2, x4) - max(x1, x3)) * (min(y2, y4) - max(y1, y3));
    }
    cout << res;
}