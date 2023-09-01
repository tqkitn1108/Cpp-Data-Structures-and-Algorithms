#include <iostream>
using namespace std;
void DectoBin(long long n)
{
    if (n != 0)
    {
        DectoBin(n / 2);
        cout << n % 2;
    }
}

int main()
{
    int T;
    long long n[100000];
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < T; i++)
    {
        DectoBin(n[i]);
        cout << "\n";
    }
}