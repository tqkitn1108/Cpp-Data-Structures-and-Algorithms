// Code by Ta Quang Kien
// Hoán vị thần kì 
#include <iostream>
#define Nmax 100000
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int N, K, A[Nmax], R[Nmax];
    cin >> N >> K;
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
    }
    int d, j;
    for (int i = 0; i < K; i++)
    {
        R[i] = A[i] % K;
        d = 1;
        j = i;
        while (A[j + K] <= N && j + K < N)// Tìm ra số lượng các phần tử của mảng lần lượt đồng dư (mod K) với R[0],..., R[K-1]
        {
            d++;// Nếu d chẵn thì hoán vị A[i] và A[i+K] cho nhau được mảng thỏa mãn
            j += K;
        }
        if (d % 2 == 1)
        {
            cout << -1;
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < (N - 1 - i) / K; j += 2)
            {
                swap(A[i + j * K], A[i + (j + 1) * K]);
            }
        }
        for (int i = 0; i < N; i++)
        {
            cout << A[i] << " ";
        }
    }
}