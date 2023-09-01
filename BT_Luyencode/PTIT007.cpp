// Code by Ta Quang Kien
// Bài toán : In ra số đẹp gần nhất lớn hơn hoặc bằng n với số đẹp là số biểu diễn trong hệ tam phân chỉ có chữ số 0 hoặc 1
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t, n[500], k, tmp, a[11], res; // a[i] là hệ số của 3^i khi phân tích n theo cơ số 3
    bool flag;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++)
    {
        k = 0;
        flag = true;
        res = n[i];
        while (n[i] >= pow(3, k))
        {
            k++;
        }
        a[k] = 0;
        tmp = k;
        for (int j = k - 1; j >= 0; j--)
        {
            a[j] = n[i] / pow(3, j);
            if (a[j] == 2)
            {
                flag = false;
                break;
            }
            else if (a[j] == 1)
            {
                n[i] -= pow(3, j);
            }
            else
                tmp = j; //Nếu có a[c] =2 thì tmp là chỉ số của mảng a[] thỏa mãn a[tmp]=0 và tmp gần chỉ số c nhất
            if (n[i] == 0)
                break;
        }
        if (!flag)
        {
            res = 0;
            a[tmp]++;
            for (int j = tmp; j <= k; j++)
            {
                res += a[j] * pow(3, j);
            }
            cout << res << "\n";
        }
        else
            cout << res << "\n";
    }
}