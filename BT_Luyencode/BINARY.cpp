// Code by Ta Quang Kien
// BINLISTED: Liệt kê chuỗi nhị phân không có hai số 0 đứng cạnh nhau
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int b[25];
    for (int i = 0; i < n; i++)
    {
        b[i] = 0;
    }
    while (true)
    {
        bool f = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (b[i] == 0 && b[i + 1] == 0)
            {
                f = false;
                break;
            }
        }
        if (f == true)
        {
            for (int i = 0; i < n; i++)
            {
                cout << b[i];
            }
            cout << "\n";
        }
        int flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (b[i] == 0)
            {
                flag = 1;
                b[i] = 1;
                for (int j = i + 1; j < n; j++)
                {
                    b[j] = 0;
                }
                break;
            }
        }
        if (flag == 0)
            break;
    }
}