#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 0)
        n = -n;
    if (n > 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0)
                cout << n / i << " ";
        }
        cout << 1;
    }
    if (n == 0)
        cout << "INF";
}