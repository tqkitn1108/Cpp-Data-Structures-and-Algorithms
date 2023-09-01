// Code by Ta Quang Kien
// Định thức ma trận vuông 3x3
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long a[3][5], k = 1, j, i, res = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    a[0][3] = a[0][0];
    a[0][4] = a[0][1];
    a[1][3] = a[1][0];
    a[2][3] = a[2][0];
    a[2][4] = a[2][1];
    j = 0;
    i = 0;
    while (i != 0 || j != 3)
    {
        k *= a[i][j];
        j++;
        i++;
        if (i == 3)
        {
            res += k;
            i = 0;
            j -= 2;
            k = 1;
        }
    }
    i = 2;
    j = 0;
    while (i != 2 || j != 3)
    {
        k *= a[i][j];
        j++;
        i--;
        if (i == -1)
        {
            res -= k;
            i = 2;
            j -= 2;
            k = 1;
        }
    }
    cout << res;
}