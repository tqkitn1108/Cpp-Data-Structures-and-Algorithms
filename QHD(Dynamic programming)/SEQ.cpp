// Code by Ta Quang Kien
// Ý tưởng giống bài DOEXAM
#include <iostream>
using namespace std;

int main()
{
    int n, k, v[6701], f[6701], v_sum[6701], tmp = 6700001, minv;
    // f[i] là giá trị nhỏ nhất của số cây không bị chặt kể từ cây i về trước trong đó cây i không bị chặt
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    if (k == 1)
        cout << 0;
    else
    {
        v_sum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            v_sum[i] = v_sum[i - 1] + v[i];
        }
        f[1] = v[1];
        for (int i = 2; i <= n; i++)
        {
            if (k >= i)
                f[i] = v[i];
            else
            {
                minv = 6700001;
                for (int j = i - k; j <= i - 1; j++)
                {
                    if (f[j] < minv)
                        minv = f[j];
                }
                f[i] = minv + v[i];
            }
        }
        for (int i = n - k + 1; i <= n; i++)
        {
            if (f[i] < tmp)
                tmp = f[i];
        }
        cout << v_sum[n] - tmp;
    }
}