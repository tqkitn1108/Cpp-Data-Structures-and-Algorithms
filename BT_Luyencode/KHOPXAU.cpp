// Nguồn tài liệu về hash: VNOI
#include <iostream>
#define ll long long
#define base 31
const ll MOD = 1000000003;
using namespace std;
ll *POW = new ll[1000005], *hashs = new ll[1000005];
ll getHashs(int i, int j)
{
    return (hashs[j] - hashs[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int m = t.length(), n = s.length();
    s = " " + s;
    t = " " + t;
    ll hasht = 0;
    for (int i = 1; i <= m; i++)
    {
        hasht = (hasht * base + t[i] - 'a' + 1) % MOD;
    }
    POW[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        POW[i] = (POW[i - 1] * base) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        hashs[i] = (hashs[i - 1] * base + s[i] - 'a' + 1) % MOD;
    }
    for (int i = 1; i <= n - m + 1; i++)
    {
        if (hasht == getHashs(i, i + m - 1))
            cout << i << " ";
    }
}