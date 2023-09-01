// Infix to postfix(Tham khảo Geeksforgeeks)
#include <iostream>
#include <vector>
using namespace std;
int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void Infixtopostfix(string s)
{
    vector<char> K;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c >= 'a' && c <= 'z')
            res += c;
        else if (c == '(')
        {
            K.push_back(c);
        }
        else if (c == ')')
        {
            while (K.back() != '(')
            {
                res += K.back();
                K.pop_back();
            }
            K.pop_back();
        }
        else
        {
            while (!K.empty() && precedence(c) <= precedence(K.back()))
            {
                res += K.back();
                K.pop_back();
            }
            K.push_back(c);
        }
    }
    while (!K.empty())
    {
        res += K.back();
        K.pop_back();
    }
    cout << res << "\n";
}

int main()
{
    int T;
    cin >> T;
    string str[100];
    for (int i = 0; i < T; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < T; i++)
    {
        Infixtopostfix(str[i]);
    }
}