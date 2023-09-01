// Code by Ta Quang Kien
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, k, a[100000], cnt = 0, res = 0, b[100000] = {}, j = 0; //b[i] là số lượng chữ số chẵn giữa hai số lẻ thứ i và i+1
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] & 1)
        {
            cnt++;
            j++;
        }
        else
        {
            b[j]++;
        }
        if (cnt >= k)
        {
            res += b[cnt - k] + 1;
        }
    }
    cout << res;
}