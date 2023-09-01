// Code by Ta Quang Kien
// Sơn nhà sao cho không có 2 nhà nào liên tiếp cùng màu
#include <iostream>
using namespace std;

int main()
{
    int n, count = 1, res = 0;
    string s, subs;
    s += 'k'; // Để vòng lặp chạy thêm 1 vòng để tính res khi có một số kí tự cuối giống nhau
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            res += count / 2;
            count = 1;
        }
    }
    cout << res;
}