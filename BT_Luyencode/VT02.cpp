// Code by Ta Quang Kien
// In ra số lớn thứ hai trong mảng
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    int k = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] != k)
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
        cout << "NOT FOUND";
    if (flag == false)
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        int a_max = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] < a_max)
            {
                cout << a[i];
                break;
            }
        }
    }
}