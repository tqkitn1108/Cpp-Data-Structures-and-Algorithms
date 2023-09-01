// Code tham khảo "truongducvuong"
#include <iostream>
using namespace std;

int main()
{
    long long n, *a = new long long[1000000], *b = new long long[1000000], count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
        if (b[a[i]] == 1)
            count++;
    }
    cout << count << "\n";
    for (int i = 0; i < n; i++)
    {
        if (b[a[i]] > 0)
        {
            cout << a[i] << " " << b[a[i]] << "\n";
        }
        b[a[i]] = 0;
    }

    delete[] a;
    delete[] b;
}
// Duyệt map:
/*map<int, int>::iterator it;
    for (it = pos.begin(); it != pos.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }*/