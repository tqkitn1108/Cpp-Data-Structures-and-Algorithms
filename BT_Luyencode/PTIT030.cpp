// Code by Ta Quang Kien
// 27/10/2021
// Kiểm tra điểm D có nằm trong tam giác ABC hay không ?
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int x[4], y[4];
    float a, b, c, d;
    for (int i = 0; i < 4; ++i)
    {
        cin >> x[i] >> y[i];
    }
    if (x[0] > x[1])
    {
        swap(x[0], x[1]);
        swap(y[0], y[1]);
    }
    if (x[0] > x[2])
    {
        swap(x[0], x[2]);
        swap(y[0], y[2]);
    }
    if (x[1] > x[2])
    {
        swap(x[1], x[2]);
        swap(y[1], y[2]);
    }
    if (x[3] <= x[0] || x[3] >= x[2])
    {
        cout << "NO";
        return 0;
    }
    if (x[3] <= x[1])
    {
        a = 1.0 * (y[1] - y[0]) / (x[1] - x[0]);
        b = y[0] - a * x[0];
        c = 1.0 * (y[0] - y[2]) / (x[0] - x[2]);
        d = y[0] - a * x[0];
        if ((a * x[3] + b < y[3] && y[3] < c * x[3] + d) || (a * x[3] + b > y[3] && y[3] > c * x[3] + d))
            cout << "YES";
        else
            cout << "NO";
    }
    else
    {
        a = 1.0 * (y[2] - y[0]) / (x[2] - x[0]);
        b = y[2] - a * x[2];
        c = 1.0 * (y[1] - y[2]) / (x[1] - x[2]);
        d = y[2] - c * x[2];
        if ((a * x[3] + b < y[3] && y[3] < c * x[3] + d) || (a * x[3] + b > y[3] && y[3] > c * x[3] + d))
            cout << "YES";
        else
            cout << "NO";
    }
}