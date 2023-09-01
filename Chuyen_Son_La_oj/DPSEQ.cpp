// Code by Ta Quang Kien
#include <iostream>
using namespace std;

int main()
{
    int n, k, a[100001], f[100001], max, S;
    // f[i] là tổng điểm lớn nhất của quãng đường từ điểm xuất phát đến điểm kết thúc tọa độ i 
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
        {
            for (int j = 1; j < i; j++)
            {
                if (a[j] > 0)
                    f[i] += a[j];
            }
        }
        else
        {
            max = f[i - k];
            for (int j = i - k; j <= i - 1; j++)
            {
                if (f[j] > max)
                    max = f[j];
            }
            f[i] += max;
        }
    }
    S = f[1];
    for (int i = 1; i <= n; i++)
    {
        if (f[i] > S)
            S = f[i];
    }
    cout << S;
}