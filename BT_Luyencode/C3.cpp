// Code by Ta Quang Kien
// 2/11/2021
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, a[100001], count = 0, b[50001] = {};
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        b[a[i]]++;
    }
    for (int i = n; i >= 1; --i)
    {
        if (b[k - a[i] * a[i]] > 0 && k - a[i] * a[i] > 0)
        {
            count += b[k - a[i] * a[i]];
        }
        b[a[i]]--;
    }
    cout << count;
}