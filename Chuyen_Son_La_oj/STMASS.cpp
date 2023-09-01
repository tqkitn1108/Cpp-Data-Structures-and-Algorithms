// Tham khảo
#include <iostream>
#include <vector>
using namespace std;
int KLNT(char c)
{
    if (c == 'C')
        return 12;
    else if (c == 'H')
        return 1;
    return 16;
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t, res, tmp;
    vector<int> vt;
    string str[1001], s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < t; i++)
    {
        s = str[i];
        res = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '(')
                vt.push_back(0);
            else if (s[j] == 'C' || s[j] == 'H' || s[j] == 'O')
                vt.push_back(KLNT(s[j]));
            else if (s[j] == ')')
            {
                tmp = 0;
                while (vt.back() != 0)
                {
                    tmp += vt.back();
                    vt.pop_back();
                }
                vt.pop_back();
                vt.push_back(tmp);
            }
            else if (s[j] >= 50 && s[j] <= 57)
            {
                tmp = vt.back() * (s[j] - 48);
                vt.pop_back();
                vt.push_back(tmp);
            }
        }
        while (!vt.empty())
        {
            res += vt.back();
            vt.pop_back();
        }
        cout << res << "\n";
    }
}