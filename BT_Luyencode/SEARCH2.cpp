// Code by Ta Quang Kien
// Tìm kiếm nhị phân 2
#include <iostream>
using namespace std;

int main()
{
    int n, m, a[100000], b[100000];
    int res;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int start, end, k;
    for (int i = 0; i < m; i++)
    {
        res = 0;
        start = 0;
        end = n - 1;
        while (start <= end)
        {
            k = (start + end) / 2;
            if (b[i] == a[k])
            {
                res = k + 1;
                end = k;
            }
            if (b[i] > a[k])
            {
                start = k + 1;
            }
            else
            {
                end = k - 1;
            }
        }
        if (res == 0)
            cout << res << " ";
        else
            cout << res << " ";
    }
}