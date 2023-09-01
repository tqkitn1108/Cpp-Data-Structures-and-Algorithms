// Code by Ta Quang Kien
// Tính pow(a,n) với 1<=n<=1000 và a rất lớn
#include <iostream>
using namespace std;
string multi(string a, string b)
{
    int n = a.length(), m = b.length();
    string res;
    int carry = 0;
    for (int i = m + n - 1; i >= 0; i--)
    {
        int temp = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            if (i - j >= 1 && i - j <= n)
            {
                int a1 = a[i - j - 1] - 48;
                int b1 = b[j] - 48;
                temp += a1 * b1;
            }
        }
        temp += carry;
        carry = temp / 10;
        res = (char)(temp % 10 + 48) + res;
    }
    while (res.length() > 1 && res[0] == '0')
        res.erase(0, 1);
    return res;
}
string power(string a, int n)
{
    if (n == 0)
        return "1";
    else
    {
        string str = multi(power(a, n / 2), power(a, n / 2));
        if (n % 2 == 0)
        {
            return str;
        }
        else
            return multi(str, a);
    }
}

int main()
{
    string a;
    int n;
    cin >> a >> n;
    cout << power(a, n);
}