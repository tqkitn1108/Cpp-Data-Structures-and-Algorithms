// Code by Ta Quang Kien
// 12/12/2021
// Chuyển số sang cách đọc (n<=1000)
#include <iostream>
#include <algorithm>
#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FORUP(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

string a[11] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi"};
string donvi[10] = {"", " mot", " hai", " ba", " tu", " lam", " sau", " bay", " tam", " chin"};
string chuc[10] = {"linh", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi"};

string READ_NUM(int n)
{
    string res = "";
    if (n >= 0 && n <= 10)
        return a[n];
    if (n < 100)
    {
        if (n == 14)
            res = "muoi bon";
        else
            res = chuc[n / 10] + donvi[n % 10];
        return res;
    }
    if (n < 1000)
    {
        if (n % 100 == 0)
            res = a[n / 100] + " tram";
        else
        {
            if ((n - 5) % 100 == 0)
                res = a[n / 100] + " tram linh nam";
            else if ((n - 14) % 100 == 0)
                res = a[n / 100] + " tram muoi bon";

            else
                res = a[n / 100] + " tram " + chuc[(n / 10) % 10] + donvi[n % 10];
        }
        return res;
    }
    if (n == 1000)
        return "mot nghin";
}
int main()
{
    fast_io;
    int t, n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        cout << READ_NUM(n) << "\n";
        t--;
    }
}