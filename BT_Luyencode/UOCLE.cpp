// Code by Ta Quang Kien
// Tìm ước số lẻ lớn nhất (<n) của số n
#include <iostream>
using namespace std;

int main()
{
    int T, n[100000];
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < T; i++)
    {
        int t = n[i];
        if (t % 2 == 1)
        {
            for (int j = 3; j * j <= t; j += 2)
            {
                if (t % j == 0)
                {
                    t /= j;
                    break;
                }
            }
            if (t == n[i])
                t = 1;
        }
        while (t % 2 == 0)
        {
            t /= 2;
        }
        cout << t << "\n";
    }
}