// Code by Ta Quang Kien
// Giải hệ phương trình bậc nhất
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    float x, y;
    long long t = a * e - b * d;
    if (t == 0 && (c * d - a * f) != 0)
    {
        cout << "VONGHIEM";
    }
    if (t == 0 && (c * d - a * f) == 0)
    {
        cout << "VOSONGHIEM";
    }
    else
    {
        if (t != 0)
        {
            x = (float)(c * e - b * f) / t;
            if (b == 0)
                y = (f - d * x) / e;
            else
                y = (c - a * x) / b;
            cout << fixed << setprecision(2) << x << " ";
            cout << fixed << setprecision(2) << y;
        }
    }
}