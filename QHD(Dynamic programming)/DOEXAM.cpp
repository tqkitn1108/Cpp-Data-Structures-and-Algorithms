// Code by Ta Quang Kien
#include <iostream>
using namespace std;
int maxvalue(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

int main()
{
    int n, k, d[26], f[26][26], res = 0;
    // f[i][j] là điểm lớn nhất mà Tí có thể đạt được khi chỉ đủ thời gian làm j bài và bài cuối cùng làm là bài thứ i
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int j = 1; j <= k; j++)
    {
        f[0][j] = 0;
    }
    f[1][1] = d[1];
    f[2][1] = d[2];
    for (int i = 3; i <= n; i++)
    {
        f[i][1] = 0;
    }
    for (int j = 2; j <= k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i < j)
                f[i][j] = f[i][i];
            else if (j <= (i - 1) / 2) // Nếu j<=(i-1)/2 thì trong i-1 bài trước đó Tí chỉ làm j-1 bài nên có 2 bài liên tiếp bị bỏ
                f[i][j] = 0;
            else
                f[i][j] = maxvalue(f[i - 1][j - 1], f[i - 2][j - 1]) + d[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i][k] > res)
            res = f[i][k];
    }
    cout << res;
}