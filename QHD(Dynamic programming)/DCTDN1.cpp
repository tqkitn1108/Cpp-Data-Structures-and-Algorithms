#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N], f[N]; //f[i] là số các số hạng trong dãy con dài nhất kết thúc tại a[i]
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    f[0] = 1;
    int max_long = 1, count;
    for (int i = 1; i < N; i++)
    {
        count = 1; // biến "count" đếm số số hạng trong dãy tăng kết thúc tại A[i]
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && f[j] >= count)
            {
                count++;
            }
            f[i] = count;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (f[i] > max_long)
            max_long = f[i];
    }
    cout << max_long;
}