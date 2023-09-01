// Tham khảo
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long n, x, y;
    cin >> n;
    cin >> x;
    for (int i = 1; i < n; i++)
    {
        cin >> y;
        x = x ^ y;// ^: Toán tử XOR
    }
    cout << x;
}