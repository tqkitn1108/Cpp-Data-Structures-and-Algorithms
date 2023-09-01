// Code by Ta Quang Kien
// Tìm mật mã (Từ "ZERO" đến "NINE") trong một chuỗi cho trước
#include <iostream>
using namespace std;
string numtostr(int n)
{
    string s;
    switch (n)
    {
    case 0:
        return s = "ZERO";
    case 1:
        return s = "ONE";
    case 2:
        return s = "TWO";
    case 3:
        return s = "THREE";
    case 4:
        return s = "FOUR";
    case 5:
        return s = "FIVE";
    case 6:
        return s = "SIX";
    case 7:
        return s = "SEVEN";
    case 8:
        return s = "EIGHT";
    case 9:
        return s = "NINE";
    }
}

int main()
{
    string s, res, str = numtostr(0);
    int j, t = 0;
    cin >> s;
    while (res != str)
    {
        res = "";
        j = 0;
        str = numtostr(t);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == str[j])
            {
                res += str[j];
                j++;
            }
        }
        t++;
        if (t == 10)
            break;
    }
    if (res == str)
        cout << res;
    else
        cout << "CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!";
}