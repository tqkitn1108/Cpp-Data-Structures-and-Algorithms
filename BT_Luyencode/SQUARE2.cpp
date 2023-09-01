// Code by Ta Quang Kien
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w[3], h[3], i;
    for (i = 0; i < 3; ++i)
    {
        cin >> h[i] >> w[i];
    }
    if (h[2] == h[1])
    {
        if (h[2] == h[0] && w[0] + w[1] + w[2] == h[0])
            cout << "YES";
        else if (h[2] == h[0] - w[0] && w[1] + w[2] == h[0])
            cout << "YES";
        else
            cout << "NO";
    }
    else if (h[2] == w[1])
    {
        if (h[2] == h[0] - w[0] && h[1] + w[2] == h[0])
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
    return 0;
}