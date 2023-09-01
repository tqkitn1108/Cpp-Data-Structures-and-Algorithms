// Code by Ta Quang Kien
// Tính tổng các số xuất hiện trong một chuỗi
#include <iostream>
using namespace std;
string sumstr(string a, string b)
{
    string res;
    int m = a.length(), n = b.length();
    if (m < n)
    {
        a = string(n - m, '0') + a;
        m = n;
    }
    if (m > n)
    {
        b = string(m - n, '0') + b;
        n = m;
    }
    int carry = 0, tmp;
    for (int i = m - 1; i >= 0; i--)
    {
        tmp = a[i] - 48 + b[i] - 48 + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res = (char)(tmp + 48) + res;
    }
    if (carry > 0)
        res = "1" + res;
    return res;
}

int main()
{
    string str, S = "0", subs = "0";
    cin >> str;
    str+="k";// Để xử lí trường hợp có số đứng ở vị trí cuối cùng của chuỗi, khi đó vòng for sẽ chạy thêm 1 lần để tính S
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            subs += str[i];
        }
        else
        {
            S = sumstr(S, subs);
            subs = "0";
        }
    }
    while (S[0] == '0')
        S.erase(0, 1);
    cout << S;
}