// Tham khảo VNOJ
#include <iostream>
#define maxN 101
#define maxV 10000
using namespace std;

int main()
{
    int N, S, a[maxN], f[maxV];
    cin >> N >> S;
    int max = 0, min_coin = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (max < a[i] && a[i] < S)
            max = a[i];
    }
    if (S > maxV)
    {
        int d = (S - maxV) / max + 1;
        S -= max * d;
        min_coin = d;
    }
    f[0] = 0;
    for (int i = 1; i <= S; i++)
    {
        f[i] = maxV;
        max = 0;
        for (int j = 0; j < N; j++)
        {
            if (a[j] <= i && f[i - a[j]] + 1 < f[i])
            {
                f[i] = f[i - a[j]] + 1;
            }
        }
    }
    min_coin += f[S];
    cout << min_coin;
}