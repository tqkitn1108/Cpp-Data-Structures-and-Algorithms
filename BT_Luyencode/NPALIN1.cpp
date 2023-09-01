// Code by Ta Quang Kien
// Số đối xứng
#include <iostream>
#define maxN 100000
using namespace std;
long luythua(int n)
{
    long lt = 1;
    for (int i = 1; i <= n; i++)
    {
        lt *= 10;
    }
    return lt;
}
int sodoixung(int n)
{
    int count;
    if (n % 2 == 1)
    {
        count = 9 * luythua((n - 1) / 2);
    }
    else
        count = 9 * luythua(n / 2 - 1);
    return count;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << sodoixung(n) << "\n";
    }
}