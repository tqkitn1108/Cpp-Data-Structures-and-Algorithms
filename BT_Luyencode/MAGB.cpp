#include <iostream>

#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FORUP(i, a, b) for (int i = a; i <= b; ++i)
#define FORDOWN(i, a, b) for (int i = a; i >= b; --i)
const ll nmax = 1e5 + 5;

using namespace std;

ll n, a[nmax], bit[nmax], ans = 0;
// Chia đoạn [1...i] thành các block theo cây BIT
// bit[i] là số lần xuất hiện của phần tử j với j nằm trong block chứa phần tử có chỉ số i, j<=i
// VD: bit[2^k] là số lần xuất hiện của các số trong đoạn [1,2^k], bit[3] là số lần xuất hiện của 3, bit[6] là số lần xuất hiện của các số trong đoạn [5,6]

ll get(ll x)
{
    ll idx = x, sum = 0;
    while (idx > 0)
    {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update(ll x, ll val)
{
    ll idx = x;
    while (idx <= nmax)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

int main()
{
    fast_io;
    cin >> n;
    FORUP(i, 1, n)
    cin >> a[i];
    FORDOWN(i, n, 1)
    {
        ans += get(a[i] - 1); // get(a[i]-1) là để tìm số các số nhỏ hơn hoặc bằng a[i]-1 đã xuất hiện trước khi duyệt đến i
        update(a[i], 1);      // Tăng số lần xuất hiện của a[i] lên 1 lần
    }
    cout << ans;
    return 0;
}