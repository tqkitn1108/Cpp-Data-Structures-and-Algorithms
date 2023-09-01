// Code by Ta Quang Kien
// 31/10/2021
// Tìm chữ số cuối cùng khác 0 của n!
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, res = 1;
    cin >> n;
    if (n == 0)
    {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {

        res *= i;
        while (res % 10 == 0)
            res /= 10;
        res %= 10000000;
    }
    res = res % 10;
    cout << res;
}