// Code by Ta Quang Kien
// 22/03/2022
#include <iostream>
#include <algorithm>
#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FOR(i, a, b) for (int i = a; i <= b; ++i)

using namespace std;

int main()
{
    fast_io;
    int t, n, x[50001], a[50001], s = 0, res = -1;
    bool b[100001];
    cin >> t >> n;
    FOR(i, 1, n)
    {
        cin >> x[i];
    }
    a[0] = 0;
    b[a[0]] = 1;
    FOR(i, 1, n)
    {
        if (x[i] < 0)
        {
            a[i] = -x[i];
            b[a[i]] = 0; // b[a[i]]=0 khi x[i] có tọa độ âm
        }
        else
        {
            a[i] = x[i];
            b[a[i]] = 1; // b[a[i]]=1 khi x[i] có tọa độ dương
        }
    }
    sort(a + 1, a + n + 1);
    FOR(i, 1, n)
    {
        if (b[a[i]] != b[a[i - 1]])
        {
            s += a[i - 1] + a[i];
        }
        else
        {
            s += a[i] - a[i - 1];
        }
        if (s > t)
        {
            res = i - 1;
            break;
        }
    }
    if (res == -1)
        cout << n; // Trường hợp res=-1 nghĩa là s<=t với mọi i trong codeblock trên
    else
        cout << res;
}