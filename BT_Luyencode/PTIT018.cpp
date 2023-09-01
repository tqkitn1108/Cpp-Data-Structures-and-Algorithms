// Code by Ta Quang Kien
// Chuỗi có độ dài theo dãy Fibonacci
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long t, n, i;
    long long g[93];
    cin >> t;
    g[1] = 1;
    g[2] = 1;
    for (int j = 3; j <= 92; ++j)
    {
        g[j] = g[j - 2] + g[j - 1];
    }
    while (t > 0)
    {
        cin >> n >> i;
        for (int j = n; j >= 1; j -= 2)
        {
            if (j == 1)
            {
                cout << 'A' << "\n";
                break;
            }
            if (j == 2)
            {
                cout << 'B' << "\n";
                break;
            }
            if (i > g[j - 2])
            {
                i -= g[j - 2];
                j++;
            }
        }
        t--;
    }
}