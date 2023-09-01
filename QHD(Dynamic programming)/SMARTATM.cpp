#include <iostream>
using namespace std;

int main()
{
    int n, M, a[21], c[100001];
    /* c[i][j] là số tờ tiền ít nhất khi đổi j tiền sử dụng mệnh giá từ a[1] đến a[i]
    C[0][j] = vô cùng (không đổi được)
    C[i][0] = 0
    C[i][j] = C[i-1][j] nếu j>ai sử dụng mệnh giá ai vào không có tác dụng gì
    C[i][j] = Min(C[i-1][j], 1+ C[i][j-ai]) min của hai cách đổi, một là không sử dụng a[i], hai là có sử dụng thì số tờ 
    thêm một và số tiền bớt đi a[i]

    Khi ta code thì chỉ cần sử dụng một mảng một chiều để tính lần lượt các hàng (hàng sau quy hoạch dựa trên hàng trước) 
    còn vô cùng sẽ dùng là m+1
    */
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    c[0] = 0;
    for (int j = 1; j <= M; j++)
    {
        c[j] = M + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= M; j++)
        {
            if (c[j] > 1 + c[j - a[i]])
                c[j] = 1 + c[j - a[i]];
        }
    }
    if (c[M] == M + 1)
        cout << -1;
    else
        cout << c[M];
}