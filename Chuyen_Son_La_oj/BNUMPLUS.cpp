// Tham khảo link: https://kienthuc24h.com/bignum-spoj-xu-ly-nguyen-lon/
#include <iostream>
using namespace std;

int main()
{
    string a, b, res;
    int s;
    cin >> a >> b;
    if (a.length() < b.length())
        a = string(b.length() - a.length(), '0') + a;
    if (b.length() < a.length())
        b = string(a.length() - b.length(), '0') + b;
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        s = a[i] - 48 + b[i] - 48 + carry;
        carry = s / 10;
        s = s % 10;
        res = (char)(s + 48) + res;
    }
    if (carry > 0)
        res = "1" + res;
    cout << res;
}