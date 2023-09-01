// Code by Ta Quang Kien
// 21/09/2022
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FOR(i, a, b) for (int i = a; i <= b; ++i)

using namespace std;
string Int2Str(int a)
{
    string s = "";
    if (a == 0)
        s = "0";
    while (a > 0)
    {
        s = (char)(a % 10 + 48) + s;
        a /= 10;
    }
    return s;
}
int Str2Int(string s)
{
    int num = 0;
    FOR(i, 0, s.length() - 1)
    {
        num = num * 10 + s[i] - 48;
    }
    return num;
}
string ReverseStr(string s)
{
    string str = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        str += s[i];
    }
    return str;
}
bool PrimeCheck(int p)
{
    if (p <= 1)
        return false;
    if (p == 2 || p == 3)
        return true;
    int i = 2;
    while (i * i <= p)
    {
        if (p % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
int m, n, count = 0, a[20000], b[20000];

int main()
{
    fast_io;
    cin >> m >> n;
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a[3] = 7;
    int j = 4, idx = 0;
    FOR(i, 1, 9999)
    {
        string s = Int2Str(i);
        a[j++] = Str2Int(s + ReverseStr(s));
    }
    FOR(i, 1, 999)
    {
        FOR(k, 0, 9)
        {
            string s = Int2Str(i);
            a[j++] = Str2Int(s + Int2Str(k) + ReverseStr(s));
        }
    }
    for (int i = 0; i < j; ++i)
    {
        if (PrimeCheck(a[i]))
            b[idx++] = a[i];
    }
    sort(b, b + idx);
    int j1 = -1, j2 = -1;
    FOR(i, 0, idx - 1)
    {
        if (b[i] >= m)
        {
            j1 = i;
            break;
        }
    }
    for (int i = idx - 1; i >= 0; --i)
    {
        if (b[i] <= n)
        {
            j2 = i;
            break;
        }
    }
    if (j1 < 0 || j2 < 0)
    {
        cout << 0;
        return 0;
    }
    if (j1 < j2)
    {
        FOR(i, j1, j2 - 1)
        {
            cout << b[i] << "\n";
        }
        cout << b[j2];
    }
    else if (j1 == j2)
    {
        cout << b[j1];
    }
    else
        cout << 0;
}