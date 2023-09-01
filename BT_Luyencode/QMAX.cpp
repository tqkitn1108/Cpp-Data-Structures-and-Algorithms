// Code by Ta Quang Kien
// 16/10/2022
#include <iostream>

#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FORUP(i, a, b) for (int i = a; i <= b; ++i)
#define nmax 1000005
const ll amin = -(1e9 + 5);

using namespace std;
ll n, Q, a[nmax], ST[4 * nmax];

void max_in_subtree(ll id, ll l, ll r)
{
    if (l == r)
    {
        ST[id] = a[l];
        return;
    }
    ll m = (l + r) / 2;
    max_in_subtree(id * 2, l, m);
    max_in_subtree(id * 2 + 1, m + 1, r);
    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}

void update(int id, int i, ll x, int l, int r)
{
    if (i < l || i > r)
    {
        return;
    }
    if (l == r)
    {
        ST[id] = x;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, i, x, l, m);
    update(id * 2 + 1, i, x, m + 1, r);
    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || u > r)
    {
        return amin;
    }
    if (u <= l && v >= r)
    {
        return ST[id];
    }
    int m = (l + r) / 2;
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main()
{
    fast_io;
    cin >> n >> Q;
    FORUP(i, 1, n)
    {
        cin >> a[i];
    }
    max_in_subtree(1, 1, n);
    while (Q > 0)
    {
        ll k, u, v;
        cin >> k >> u >> v;
        if (k == 1)
            update(1, u, v, 1, n);
        else
        {
            cout << get(1, 1, n, u, v) << " ";
        }
        Q--;
    }
}