#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ull unsigned long long
#define ld long double
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
using namespace std;

vector<pair<ull, int> > f;
ull nn, ans1, ans2;

ull lehmann(ull n)
{
    if (n == 3)
        return n;
    ull sqrt3_n_up = ceil(pow((ld)n, (ld)1.0 / 3));
    for (ull i = 2; i <= sqrt3_n_up; i++)
        if (n % i == 0)
            return i;
    ld sqrt_n = sqrt((ld)n);
    ld sqrt6_n = pow((ld)n, (ld)1.0 / 6);
    for (ull k = 1; k <= sqrt3_n_up; k++)
    {
        ld sqrt_k = sqrt((ld)k);
        ull l = ceil(2 * sqrt_k * sqrt_n);
        ull r = floor(2 * sqrt_k * sqrt_n + sqrt6_n / (4 * sqrt_k));
        for (ull a = l; a <= r; a++)
        {
            ull b = sqrt((ld)(a * a - 4 * k * n));
            if (b * b == a * a - 4 * k * n)
            {
                ull d = __gcd(a + b, n);
                return min(d, n / d);
            }
        }
    }
    return n;
}

int main()
{
    fast_io;
    cin >> nn;
    ull p = lehmann(nn), power = 0, res = 1;
    while (p < nn)
    {
        while (nn % p == 0)
        {
            nn /= p;
            power++;
        }
        res *= (power + 1);
        p = lehmann(nn);
        power = 0;
    }
    if (nn > 1)
    {
        res *= 2;
    }
    cout << res;
    return 0;
}
