// Code by Ta Quang Kien
// Cho 1 đồ thị liên thông, phá một cạnh để tăng số thành phần liên thông, tìm số cách phá
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, a[100][100], res = 0, tmp1, b[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) // Tính với mỗi i thì có thể phá vỡ bao nhiêu cây cầu mà có 1 đầu là thành phố i
    {
        tmp1 = 0;
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 1)
                b[tmp1++] = j; // Mảng b[] lưu các thành phố mà có cầu nối trực tiếp với thành phố i
        }
        for (int j = 0; j < tmp1; ++j)
        {
            for (int t = 0; t < tmp1; ++t)
            {
                if (a[b[j]][b[t]] == 1)
                {
                    res--;
                    break;
                }
            }
            res++;
        }
    }
    cout << res / 2;
}