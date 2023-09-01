// Code by Ta Quang Kien
// Ý tưởng giống bài STMASS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t, res, tmp, k;
    string str[20], s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> str[i];
    }
    vector<int> vt;
    for (int i = 0; i < t; i++)
    {
        s = str[i];
        res = 0;
        vt.push_back(-1);// Thêm vào để trường hợp không có số 0 hoặc -1 đứng ở đầu vector thì vẫn cập nhật được res ở (*)
        k = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '(')
            {
                vt.push_back(0);
                k++;
            }
            else if (k == 0)
            {
                vt.push_back(-1);
                continue;
            }
            else
            {
                k--;
                tmp = 2;
                while (vt.back() != 0)
                {
                    tmp += vt.back();
                    vt.pop_back();
                }
                vt.pop_back();
                vt.push_back(tmp);
            }
        }
        tmp = 0;
        while (!vt.empty())
        {
            if (vt.back() != 0 && vt.back() != -1)
            {
                tmp += vt.back();
                vt.pop_back();
            }
            else // (*)
            {
                vt.pop_back();
                if (tmp > res)
                    res = tmp;
                tmp = 0;
            }
        }
        cout << res << "\n";
    }
}