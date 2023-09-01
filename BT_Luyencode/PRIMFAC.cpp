// Phân tích ra thừa số nguyên tố (tham khảo)
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int count, primedivisor = 0;
    bool flag;
    long long tmp = n;
    for (int i = 2; i <= n; i++)
    {
        flag = false;
        while (n % i == 0)
        {
            if (!flag)
                primedivisor++;
            n = n / i;
            flag = true;
        }
    }
    cout << primedivisor << '\n';
    for (int i = 2; i <= tmp; i++)
    {
        count = 0;
        flag = false;
        while (tmp % i == 0)
        {
            tmp = tmp / i;
            count++;
            flag = true;
        }
        if (flag)
            cout << i << " " << count << '\n';
    }
}