// Tham khảo
#include <iostream>
using namespace std;

int main()
{
    int n, k, comb = 1;
    cin >> n >> k;
    if (k <= n)
    {
        for (int i = 1; i <= k; i++)
        {
            comb = comb * (n - i + 1) / i;
        }
        cout << comb;
    }
}