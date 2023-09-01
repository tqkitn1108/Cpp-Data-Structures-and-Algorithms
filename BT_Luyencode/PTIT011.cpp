// Code by Ta Quang Kien
// Cho n chấm tròn, kiểm tra xem có thể xếp thành 1 tam giác cân có độ dài cạnh >=2 hay không
#include <iostream>
#include <cmath>
using namespace std;
long long sqr_check(long long t)
{
    long long sqr, tmp;
    if (t >= 1000000)
    {
        tmp = t / 1000000;
        sqr = (int)sqrt(tmp);
        for (long long i = sqr * 1000; i * i <= t; i++)
        {
            if (i * i == t)
                return i;
        }
    }
    else if (sqrt(t) == (int)sqrt(t))
        return sqrt(t);
    return -1;
}

int main()
{
    long long n, denta, temp;
    cin >> n;
    if (n == 3)
        cout << "YES";
    if (n == 0 || n == 1 || n == 2 || n == 5)
        cout << "NO";
    else if (sqr_check(n) != -1)
    {
        cout << "YES";
    }
    else
    {
        denta = 1 + 8 * n;
        if (sqr_check(denta) != -1)
        {
            temp = sqr_check(denta);
            if ((temp - 1) % 2 == 0)
                cout << "YES";
            else
                cout << "NO";
        }
        else
            cout << "NO";
    }
}