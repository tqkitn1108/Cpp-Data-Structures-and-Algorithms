// Code by Ta Quang Kien
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> VT;
    vector<int> index_open;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            VT.push_back(s[i]);
            index_open.push_back(i + 1);
        }
        else
        {
            VT.pop_back();
            cout << index_open.back() << " " << i + 1 << "\n";
            index_open.pop_back();
        }
    }
}