// Code by Ta Quang Kien
// Liệt kê số chính phương trong ma trận theo thứ tự
#include <iostream>
#include <cmath>
using namespace std;
bool sqr_check(int n)
{
    if (n>=0 && sqrt(n) == (int)sqrt(n))
        return true;
    return false;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int m, n, A[100][100], sqr[10001];
    cin >> m >> n;
    int t = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            if (sqr_check(A[i][j]))
            {
                sqr[t] = A[i][j];
                t++;
            }
        }
    }
    if (t == 0)
        cout << "NOT FOUND";
    else
    {
        for (int i = 0; i < t; i++)
        {
            for (int j = i + 1; j < t; j++)
            {
                if (sqr[i] > sqr[j])
                    swap(sqr[i], sqr[j]);
            }
        }
        int i, j, c;
        for (i = 0; i < t; i += j)
        {   j=1;
            c = sqr[i];
            cout << c << " ";
            while (c == sqr[i + j] && i+j<t)
            {
                j++;
            }
        }
    }
}