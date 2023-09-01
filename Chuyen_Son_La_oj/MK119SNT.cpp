// Tham khảo
// Đếm số số nguyên tố trong đoạn [L,R]
#include <iostream>
using namespace std;

int main()
{
    int T, i;
    cin >> T;
    int L[100000], R[100000], *K = new int[1000001];
    for (i = 0; i < T; i++)
    {
        cin >> L[i] >> R[i];
    }
    bool check[1000001];
    check[1] = false;
    for (int i = 2; i <= 1000000; i++)
    {
        check[i] = true;
    }
    for (int i = 2; i <= 1000000; i++)
    {
        if (check[i])
        {
            for (int j = i * 2; j <= 1000000; j += i)
            {
                check[j] = false;
            }
        }
    }
    K[0] = 0;
    for (i = 1; i <= 1000000; i++)
    {
        if (check[i])
            K[i] = K[i - 1] + 1;
        else
            K[i] = K[i - 1];
    }
    for (i = 0; i < T; i++)
    {
        cout << K[R[i]] - K[L[i] - 1] << "\n";
    }
    delete[] K;
}