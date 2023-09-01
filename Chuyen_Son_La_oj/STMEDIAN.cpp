// Code by Ta Quang Kien
// Truy vấn trung vị
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, m, *a = new int[1000001], j, tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    tmp = n;
    if (n % 2 == 1)
    {
        j = 0;
        while (m > 0)
        {
            if (tmp % 2 == 1)
            {
                cout << a[(n + 1) / 2 + j] << " ";
                j++;
            }
            else
            {
                cout << a[(n + 1) / 2 - j] << " ";
            }
            tmp--;
            m--;
        }
    }
    else
    {
        j = 0;
        while (m > 0)
        {
            if (tmp % 2 == 0)
            {
                cout << a[(n + 1) / 2 - j] << " ";
                j++;
            }
            else
            {
                cout << a[(n + 1) / 2 + j] << " ";
            }
            tmp--;
            m--;
        }
    }
}