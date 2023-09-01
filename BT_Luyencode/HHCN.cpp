// Code by Ta Quang Kien
#include <iostream>
#include <cmath>
using namespace std;
void swap(long long &a, long long &b)
{
    long long tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    unsigned long long S1, S2, S3, a, b, h,i;
    double k;
    cin >> S1 >> S2 >> S3;
    if (S2 > S1)
        swap(S1, S2);
    if (S3 > S1)
        swap(S1, S3);
    if (S3 > S2)
        swap(S3, S2);
    k = S3 * 1.0 / S1 - 0.00001;
    k *= S2;
    i = (long long)sqrt(k);
    if(i==0 || i==1) i++;
    while (S3 % i != 0)
    {
        i++;
    }
    h = i;
    b = S3 / h;
    a = S2 / h;
    cout << (4 * (a + b + h)) % 1000000007;
}