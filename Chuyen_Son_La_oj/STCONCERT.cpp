// Tham khảo của "Con Vịt Kutee"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h[100001];
    long long count, res = 0;
    vector<int> vt;
    map<int, int> same_h;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (!vt.empty() && vt.back() < h[i])
        {
            res++;
            same_h[vt.back()]--;
            vt.pop_back();
        }
        if (!vt.empty() && vt.back() > h[i])
        {
            res++;
        }
        if (!vt.empty() && vt.back() == h[i])
        {
            if (vt.size() > same_h[h[i]])
                res += same_h[h[i]] + 1;
            else
                res += same_h[h[i]];
        }
        vt.push_back(h[i]);
        same_h[h[i]]++; // Same_h[h[i]] là số người có cùng chiều cao h[i] đứng trước người thứ i(tính cả người thứ i) và nhìn thấy i
    }
    cout << res;
}