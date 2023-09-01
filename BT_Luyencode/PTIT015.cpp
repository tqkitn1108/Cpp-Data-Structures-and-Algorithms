// Tham khảo
// Liệt kê dãy ngoặc đúng có độ dài n ( n chẵn)
// Ý tưởng: Quy về dãy nhị phân với '(' tương ứng chữ số 0 , ')' tương ứng chữ số 1. Giải bằng quay lui:
#include <iostream>
using namespace std;
int n, a[21], count = 0;
void print()
{
    count++;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
            cout << "(";
        else
            cout << ")";
    }
    cout << "\n";
}
void Try(int i, int temp)// temp là số lượng chữ số 0 của dãy tính đến chỉ số i
{

    for (int j = 0; j < 2; j++)
    {
        if (j == 0)
            temp++;
        else
            temp--;
        if (2 * temp > n || 2 * temp < i)
            continue;
        a[i] = j;
        if (i == n)
        {
            print();
            return;// kiểu return trong hàm void dùng để thoát ra khỏi hàm
        }
        Try(i + 1, temp);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n;
    Try(1, 0);
    cout << count;
    return 0;
}