#include <iostream>

#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FORUP(i, a, b) for (int i = a; i <= b; ++i)

using namespace std;

int l, r, prime[1000001], k, p[10], count[1000001];
ll res = 0;
bool visited[1000001];
void dfs(int u)
{
    visited[u] = true;
    if (u >= l && u <= r)
        count[u] = 1;
    for (int i = 1; i <= k; ++i)
    {
        ll v = 1LL * p[i] * u; //  Ép kiểu từ int về long long ta nhân với 1LL
        if (v > r)
            return;
        if (visited[v])
            continue;
        dfs(v);
        count[u] += count[v]; // count[u] là số các số có cùng prod với u nằm trong [l,r], tính cả chính nó(prod là tích các thừa số nt của u)
    }
}

int main()
{
    fast_io;
    cin >> l >> r;
    FORUP(i, 1, r)
    {
        prime[i] = i;
    }
    for (int i = 2; i * i <= r; ++i)
    {
        if (prime[i] == i)
        {
            for (int j = i * i; j <= r; j += i)
            {
                if (prime[j] == j)
                    prime[j] = i; // prime[j] là ước nguyên tố nhỏ nhất của j
            }
        }
    }
    FORUP(i, max(2, l), r)
    {
        ll prod = 1, temp = i;
        k = 0;
        while (temp > 1)
        {
            p[++k] = prime[temp];
            prod *= p[k];
            while (temp % p[k] == 0)
                temp /= p[k];
        }
        if (!visited[prod])
            dfs(prod);
        count[prod]--;
        res += count[prod];
    }
    cout << res;
}