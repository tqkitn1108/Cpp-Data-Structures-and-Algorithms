// Code by Ta Quang Kien
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string res;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                string temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        res += a[i];
    }
    cout << res;
}