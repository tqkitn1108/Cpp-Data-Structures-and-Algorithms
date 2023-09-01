// Code by Ta Quang Kien
#include <iostream>
#define MOD 1000000007
using namespace std;
int Power(int a, int b)
{
    if (b == 0)
        return 1;
    else
    {
        long long t = Power(a, b / 2) % MOD;
        long long j = (t * t) % MOD;
        if (b % 2 == 0)
            return j;
        else
            return (a * j) % MOD;
    }
}
int main()
{
    int a, n;
    cin >> a >> n;
    cout << Power(a, n);
}