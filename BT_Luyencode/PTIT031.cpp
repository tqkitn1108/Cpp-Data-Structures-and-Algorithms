// Code by Ta Quang Kien
// Tương tự bài SQUARE2
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[3], b[3], i;
    bool flag = 0;
    for (i = 0; i < 3; ++i)
    {
        cin >> a[i] >> b[i];
        if (a[i] < b[i])
            swap(a[i], b[i]);
    }
    if (a[0] < a[1])
    {
        swap(a[0], a[1]);
        swap(b[0], b[1]);
    }
    if (a[0] < a[2])
    {
        swap(a[0], a[2]);
        swap(b[0], b[2]);
    }
    if (a[1] < a[2])
    {
        swap(a[2], a[1]);
        swap(b[2], b[1]);
    }
    if (a[2] == a[1])
    {
        if (a[2] == a[0] && b[0] + b[1] + b[2] == a[0])
            flag = 1;
        else if (a[2] == a[0] - b[0] && b[1] + b[2] == a[0])
            flag = 1;
    }
    else if (a[2] == b[1])
    {
        if (a[2] == a[0] - b[0] && a[1] + b[2] == a[0])
            flag = 1;
    }
    if (flag)
        cout << a[0];
    else
        cout << 0;
}