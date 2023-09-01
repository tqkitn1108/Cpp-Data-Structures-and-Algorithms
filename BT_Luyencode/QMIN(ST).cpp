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
const ll amax = 1e9 + 5;

using namespace std;
ll n, Q, a[nmax], ST[4*nmax];

void min_in_subtree(ll id, ll l, ll r)
{
    if (l == r)
    {
        ST[id] = a[l];
        return;
    }
    ll m = (l + r) / 2;
    min_in_subtree(id * 2, l, m);
    min_in_subtree(id * 2 + 1, m + 1, r);
    ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
}
ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (v < l || u > r)
    {
        return amax;
    }
    if (u <= l && v >= r)
    {
        return ST[id];
    }
    ll m = (l + r) / 2;
    return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main()
{
    fast_io;
    cin >> n >> Q;
    FORUP(i, 1, n)
    {
        cin >> a[i];
    }
    min_in_subtree(1, 1, n);
    while (Q > 0)
    {
        ll u, v;
        cin >> u >> v;
        cout << get(1, 1, n, u, v) << " ";
        Q--;
    }
}