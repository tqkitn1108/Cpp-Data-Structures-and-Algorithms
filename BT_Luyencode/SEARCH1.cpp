// Code by Ta Quang Kien
// Tìm kiếm nhị phân 
#include <iostream>
using namespace std;

int main()
{
    int n, m, a[100000], b[100000];
    char res;
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
        start = 0;
        end = n - 1;
        k = (start + end) / 2;
        while (start <= end)
        {
            if (b[i] == a[k])
            {
                res = '1';
                break;
            }
            if (b[i] > a[k])
            {
                res = '0';
                start = k + 1;
                k = (start + end) / 2;
            }
            else
            {
                res = '0';
                end = k - 1;
                k = ((start + end) / 2);
            }
        }
        cout << res;
    }
}