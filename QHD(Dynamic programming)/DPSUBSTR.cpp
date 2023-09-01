// Xâu con chung dài nhất
#include <iostream>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    int lA = A.length(), lB = B.length();
    int f[lA + 1][lB + 1];
    for (int i = 0; i <= lB; i++)
    {
        f[0][i] = 0;
    }
    for (int i = 0; i <= lA; i++)
    {
        f[i][0] = 0;
    }
    for (int i = 1; i <= lA; i++)
    {
        char x1 = A[i - 1];
        for (int j = 1; j <= lB; j++)
        {
            char x2 = B[j - 1];
            if (x1 == x2)
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else
            {
                if (f[i][j - 1] > f[i - 1][j])
                    f[i][j] = f[i][j - 1];
                else
                    f[i][j] = f[i - 1][j];
            }
        }
    }
    cout << f[lA][lB];
}