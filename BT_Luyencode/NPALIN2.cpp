//Tham khảo
#include <iostream>
#define ll long long
using namespace std;
ll create_npal(ll front, ll nlen)
{
    ll t = front, back = 0;
    if (nlen % 2 == 1)
        t /= 10;
    while (t > 0)
    {
        back = back * 10 + t % 10;
        t /= 10;
        front *= 10;
    }
    return front + back;
}
ll npalin(ll n)
{
    ll n_len = 0, fr_len, i, front, res, temp = n;
    while (temp > 0)
    {
        temp /= 10;
        n_len++;
    }
    front = n;
    fr_len = (n_len + 1) / 2;
    for (i = 0; i < n_len - fr_len; i++)
    {
        front /= 10;
    }
    if (create_npal(front, n_len) > n)
        front--;
    if (n_len % 2 == 1)
    {
        ll a = 1;
        for (i = 1; i < fr_len; i++)
            a *= 10;
        res = front * 2 - (front - a + 1); //Từ a đến front có (front - a + 1) số, mỗi số tạo ra 1 npal, từ 1 đến a-1 mỗi số tạo ra 2 npal
    }
    else
    {
        ll b = 1;
        for (i = 1; i <= fr_len; i++)
            b *= 10;
        res = front * 2 + (b - 1 - front); // Từ 1 đến front, mỗi số tạo ra 2 npal, từ front +1 đến b-1, mỗi số tạo ra 1 npal thỏa mãn
    }
    return res;
}

int main()
{
    ll l, r;
    while (cin >> l >> r)
    {
        cout << npalin(r) - npalin(l - 1) << "\n";
    }
}