// Code by Ta Quang Kien
#include <iostream>
#define nmax 100001
using namespace std;

int main()
{
    int n, k, w[nmax], u[nmax], v[nmax];
    long long prefix_sum[nmax];
    cin >> n >> k;
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        prefix_sum[i] = prefix_sum[i - 1] + w[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> u[i] >> v[i];
    }
    for (int i = 0; i < k; i++)
    {
        cout << prefix_sum[v[i]] - prefix_sum[u[i] - 1] << " ";
    }
}