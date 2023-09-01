// Code by Ta Quang Kien
// 20/03/2022
#include <iostream>
#include <cmath>

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; ++i)

using namespace std;

int main()
{ // Ta xét 1/4 hình là hình vuông NxN(góc trên bên phải của hình 2Nx2N, giả sử tâm có tọa độ (0,0) )
    fast_io;
    int t, n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        if (n == 0)
        {
            cout << 0 << " " << 0 << "\n";
        }
        else
        {
            int res1 = 0, res2 = 0, res3; // res1, res2 lần lượt là số ô vuông nằm hoàn toàn bên trong và bên ngoài đường tròn
            float y;
            FOR(i, 1, n - 1)
            {
                y = sqrt((n - 0.5) * (n - 0.5) - i * i); // y là tung độ tương ứng với từng hoành độ x=i
                res1 += (int)y;
                res2 += n - (int)y - 1;
            }
            res3 = n * n - res1 - res2; // res3: số ô vuông bị cắt bởi đường tròn
            cout << res3 * 4 << " " << res1 * 4 << "\n";
        }
        t--;
    }
}