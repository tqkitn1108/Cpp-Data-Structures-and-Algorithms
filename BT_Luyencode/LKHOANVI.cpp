// Code by Ta Quang Kien
#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n, gt = 1;
    cin >> n;
    int a[9];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    while (true)
    {
        for (int w = 0; w < n; w++)
        {
            cout << a[w] << " ";//Lưu ý: Để không in ra khoảng trắng thừa thì chỉ in dòng này với w từ 0->n-2, cout riêng a[n-1]
        }
        cout << "\n";
        int j = 0;
        if (a[n - 2] < a[n - 1])
        {
            swap(a[n - 2], a[n - 1]);
            continue;
        }
        for (int t = n - 2; t >= 0; t--)
        {
            if (a[t] < a[t + 1])
            {
                j = t + 1;
                break;
            }
        }
        if (j > 0)
        {
            for (int t = n - 1; t >= j; t--)
            {
                if (a[t] > a[j - 1])
                {
                    swap(a[t], a[j - 1]);
                    break;
                }
            }
            int b = j, c = n - 1;
            while (b < c)
            {
                swap(a[b], a[c]);
                b++;
                c--;
            }
        }
        if(j==0){
            break;
        }
    }
}