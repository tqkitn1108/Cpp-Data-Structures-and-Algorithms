// Liệt kê số nguyên tố trong khoảng [A;B]
#include <iostream>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    bool check[B + 1];
    for (int i = 2; i <= B; i++)
    {
        check[i] = true;
    }
    check[1]=false;
    for (int i = 2; i <= B; i++)
    {
        if (check[i] == true)
        {
            for (int j = i * 2; j <= B; j += i)
            {
                check[j] = false;
            }
        }
    }
    for (int i = A; i <= B; i++)
    {
        if (check[i])
        {
            cout << i << "\n";
        }
    }
}