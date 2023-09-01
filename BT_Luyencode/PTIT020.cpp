// Code by Ta Quang Kien
#include <iostream>
using namespace std;

int main()
{
    string s;
    long long k, n;
    cin >> k >> s;
    n = s.length();
    while (k > n)
    {
        n *= 2;
    }
    while (n > s.length())
    {
        if (k - n / 2 == 1)
            k = n / 2;
        else if (k - n / 2 > 1)
            k = k - n / 2 - 1;
        n /= 2;
    }
    cout << s[k - 1];
}