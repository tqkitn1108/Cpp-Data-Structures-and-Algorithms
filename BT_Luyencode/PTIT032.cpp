// Tham khảo
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, a[200002], cost, top, j;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cost = 1;
        top = i;
        j = i - 1;
        while (a[j] < a[top] && j > 0)
        {
            j--;
            top--;
            cost++;
        }
        top = i;
        j = i + 1;
        while (a[top] > a[j] && j <= n)
        {
            top++;
            j++;
            cost++;
        }
        cout << cost << " ";
    }
}
