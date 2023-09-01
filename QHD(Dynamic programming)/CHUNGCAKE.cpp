// Code by Ta Quang Kien
// Giống bài THUHOACH
#include <iostream>
using namespace std;
int main()
{
    int n, V, v[31], f[31][2001];
    /* f[i][j] là thể tích bánh chưng (từ cái thứ nhất tới cái thứ i) lớn nhất có thể luộc vào nồi có thể tích j
    f[i][0]=f[0][j]=0
    f[i][j]=f[i-1][j] nếu trong nồi không chứa cái bánh thứ i
    f[i][j]=max(v[i]+f[i-1][j-v[i]],f[i-1][j]) là max của 2 trường hợp trong nồi có cái bánh thứ i và không có cái bánh thứ i*/
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = 0;
    }
    for (int j = 1; j <= V; j++)
    {
        f[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (j == v[i])
                f[i][j] = j;
            else if (j > v[i] && v[i] + f[i - 1][j - v[i]] > f[i - 1][j])
            {
                f[i][j] = v[i] + f[i - 1][j - v[i]];
            }
            else
                f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][V];
}