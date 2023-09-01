// Code by Ta Quang Kien
#include <iostream>
using namespace std;
int UCLN(int m, int n)
{
    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int sodaonguoc(int k)
{
    int q = 0;
    while (k >= 10)
    {
        q = q + k % 10;
        k = k / 10;
        q = q * 10;
    }
    q += k;
    return q;
}

int main()
{
    int a, b, count = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (UCLN(i, sodaonguoc(i)) == 1)
        {
            count++;
        }
    }
    cout << count;
}