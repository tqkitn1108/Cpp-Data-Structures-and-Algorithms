// Code by Ta Quang Kien
// Ma trận xoắn ốc
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, r, l, t, u, a[51][51], k; // r,l,t,u là right ,left,top,under
    cin >> n;
    r = n, l = 1, t = 1, u = n, k = 1;
    while (k <= n * n)
    {
        for (int i = l; i <= r; i++)
        {
            a[t][i] = k;
            k++;
        }
        t++;
        for (int i = t; i <= u; i++)
        {
            a[i][r] = k;
            k++;
        }
        r--;
        for (int i = r; i >= l; i--)
        {
            a[u][i] = k;
            k++;
        }
        u--;
        for (int i = u; i >= t; i--)
        {
            a[i][l] = k;
            k++;
        }
        l++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " "; // Nếu sau a[i][n] không có " "( dấu cách) thì WA
        }
        cout << "\n";
    }
}