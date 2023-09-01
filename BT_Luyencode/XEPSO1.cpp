#include <iostream>
#define nmax 38
using namespace std;

int main()
{
    int T, n[nmax];
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n[i];
    }
    string min, max;
    int t;
    for (int i = 0; i < T; i++)
    {
        t = n[i] / 7;
        if (n[i] == 2)
            min = "1";
        if (n[i] == 3)
            min = "7";
        if (n[i] == 4)
            min = "4";
        if (n[i] == 5)
            min = "2";
        if (n[i] == 6)
            min = "6";
        if (n[i] == 10)
            min = "22";
        if (n[i] >= 7 && n[i] != 10)
        {
            switch (n[i] % 7)
            {
            case 0:
                min = string(t, '8');
                break;
            case 1:
                min = "10" + string(t - 1, '8');
                break;
            case 2:
                min = "1" + string(t, '8');
                break;
            case 3:
                min = "200" + string(t - 2, '8');
                break;
            case 4:
                min = "20" + string(t - 1, '8');
                break;
            case 5:
                min = "2" + string(t, '8');
                break;
            case 6:
                min = "6" + string(t, '8');
                break;
            }
        }
        cout << min << " ";
        if (n[i] % 2 == 0)
            max = string(n[i] / 2, '1');
        if (n[i] % 2 == 1)
            max = "7" + string(n[i] / 2 - 1, '1');
        cout << max << "\n";
    }
}