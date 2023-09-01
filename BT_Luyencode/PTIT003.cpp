// Code by Ta Quang Kien
// In ra hoán vị thỏa mãn là 1 hoán vị thỏa mãn đề bài của n số nguyên dương đầu tiên
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long n, p[100002], q[100002], pmin = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> q[i];
    }
    p[1] = 1;
    q[1] = p[1];
    for (int i = 2; i <= n; i++)
    {
        p[i] = p[i - 1] + q[i];
        q[i] = p[i];
    }
    sort(q + 1, q + n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (q[i] == q[i - 1]) // Kiểm tra điều kiện phân biệt của các phần tử trong q[]( hay chính là trong p[])
        {
            pmin = -1;
            break;
        }
    }
    if (pmin == 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (p[i] < pmin)
                pmin = p[i];
        }
        if (pmin < 1)
        {
            pmin = 1 - pmin;
            for (int i = 1; i <= n; i++)
            {
                p[i] += pmin; //Tịnh tiến các phần tử của p[] để đảm bảo các phần tử đều nguyên dương
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (p[i] > n)
            {
                pmin = -1;
                break;
            }
        }
        if (pmin > 0)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << p[i] << " ";
            }
        }
    }
    if (pmin == -1)
        cout << pmin;
}