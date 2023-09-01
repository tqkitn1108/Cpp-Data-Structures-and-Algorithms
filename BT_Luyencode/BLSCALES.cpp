// Tham Khảo
#include <iostream>
#define fw(i, a, b) for (int i = a; i <= b; ++i)
#define dw(i, a, b) for (int i = a; i >= b; --i)
#define maxn 21
#define maxm 100001
#define maxv 1000001
using namespace std;
int n, m, w[maxn];
bool f[maxv] = {};
void backtrack(int i, int W)
{
    if (i > n)
    {
        f[W] = 1;
        return;
    }
    backtrack(i + 1, W);
    if (W + w[i] < maxv)
        backtrack(i + 1, W + w[i]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n >> m;
    fw(i, 1, n)
    {
        cin >> w[i];
    }
    backtrack(1, 0);
    string s(m, '0');
    int v;
    fw(i, 1, m)
    {
        cin >> v;
        if (f[v])
            s[i - 1] = '1';
    }
    cout << s;
}