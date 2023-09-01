// Code by Ta Quang Kien
// 23/10/2022
#include <iostream>

#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FORUP(i, a, b) for (int i = a; i <= b; ++i)
#define nmax 100005
using namespace std;

ll n, q, a[nmax];
struct Node
{
    ll lazy;
    ll sum;
} ST[nmax * 4];
void Build(int id, int l, int r)
{
    if (l == r)
    {
        ST[id].sum = a[l];
        return;
    }
    int m = (l + r) >> 1;
    Build(id * 2, l, m);
    Build(id * 2 + 1, m + 1, r);
    ST[id].sum = ST[id * 2].sum + ST[id * 2 + 1].sum;
}
void Down(int id, int l, int r)
{
    ll t = ST[id].lazy;
    ST[id].sum += (r - l + 1) * t;
    if (l != r)
    {
        ST[id * 2].lazy += t;
        ST[id * 2 + 1].lazy += t;
    }
    ST[id].lazy = 0;
}
void update(int id, int l, int r, int u, int v, ll val)
{
    if (ST[id].lazy != 0)
    {
        Down(id, l, r);
    }
    if (v < l || r < u)
        return;
    if (u <= l && r <= v)
    {
        ST[id].lazy += val;
        Down(id, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);
    ST[id].sum = ST[id * 2].sum + ST[id * 2 + 1].sum;
}
ll get(int id, int l, int r, int u, int v)
{
    if (ST[id].lazy != 0)
    {
        Down(id, l, r);
    }
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return ST[id].sum;
    int m = (l + r) >> 1;
    return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
}

int main()
{
    fast_io;
    cin >> n >> q;
    FORUP(i, 1, n)
    {
        cin >> a[i];
    }
    Build(1, 1, n);
    while (q--)
    {
        ll k, u, v, x;
        cin >> k;
        if (k == 1)
        {
            cin >> u >> v >> x;
            update(1, 1, n, u, v, x);
        }
        else
        {
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << "\n";
        }
    }
}