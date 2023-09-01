// Tham khảo ý tưởng
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> pos;
    int n, m, a[100001], b[100001], i;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for (i = 1; i <= m; i++)
    {
        pos[b[i]] = 0;
    }
    for (i = n; i >= 1; i--)
    {
        pos[a[i]] = i; // lưu vị trí nhỏ nhất của a[i] trong mảng a
    }
    for (i = 1; i <= m; i++)
    {
        cout << pos[b[i]] << " ";
    }
}