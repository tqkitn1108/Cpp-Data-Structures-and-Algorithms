// Code by Ta Quang Kien
// Sắp xếp thứ tự xe cho cuộc diễu hành
#include <iostream>
#include <vector>
#define nmax 100000
using namespace std;
bool cansort(int a[], int n)
{
    vector<int> K;
    vector<int> J;
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != j)
        {
            K.push_back(a[i]);
        }
        else
        {
            j++;
            J.push_back(a[i]);
            if (K.size() != 0)
            {
                while (K.back() == j)
                {
                    J.push_back(K.back());
                    K.pop_back();
                    j++;
                }
            }
        }
    }
    if (J.size() == n)
        return true;
    return false;
}

int main()
{
    int n, a[nmax];
    while (cin >> n)
    {
        if (n == 0)
            break;
        else
        {
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
        }
        if (cansort(a, n))
            cout << "yes"
                 << "\n";
        else
            cout << "no"
                 << "\n";
    }
}