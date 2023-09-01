// Code by Ta Quang Kien
// Đếm số chính phương
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long L, R;
    cin >> L >> R;
    if (sqrt(L) == (int)sqrt(L))
    {
        cout << (int)sqrt(R) - sqrt(L) + 1;
    }
    else
        cout << (int)sqrt(R) - (int)sqrt(L);
}