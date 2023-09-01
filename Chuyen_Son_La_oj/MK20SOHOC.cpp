// Code by Ta Quang Kien
// Liệt kê các ước nguyên dương của n
#include <iostream>
using namespace std;
void lietkeuoc(int i, int n)
{
    while (n % i != 0 && i * i <= n)
        i++;
    if (n % i == 0 && i * i <= n)
    {
        if (i * i == n)
        {
            cout << i << " ";
        }
        else
        {
            cout << i << " ";
            lietkeuoc(i + 1, n);
            cout << n / i << " ";
        }
    }
}

int main()
{
    int T, n[1000];
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < T; i++)
    {
        lietkeuoc(1, n[i]);
        cout << "\n";
    }
}