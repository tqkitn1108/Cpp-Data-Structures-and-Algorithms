// Code by Ta Quang Kien
// Truy vấn với ngăn xếp ( Query with stack)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T, query, n;
    cin >> T;
    vector<int> A;
    while (T > 0)
    {
        T--;
        cin >> query;
        if (query == 1)
        {
            cin >> n;
            A.push_back(n);
        }
        if (query == 2)
        {
            if (A.size() == 0)
                continue;
            else
                A.pop_back();
        }
        if (query == 3)
        {
            if (A.size() == 0)
                cout << "Empty!"
                     << "\n";
            else
                cout << A.back() << "\n";
        }
    }
}