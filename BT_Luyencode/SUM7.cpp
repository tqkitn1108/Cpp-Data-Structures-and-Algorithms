// Code by Ta Quang Kien
// Căn bậc 2 lồng nhau
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int t, n[100000];
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n[i];
    }
    double s;
    for (int j = 0; j < t; j++) {
        s = 0;
        if (n[j] >= 100) {
            for (int i = n[j] - 5; i <= n[j]; i++) {
                s = sqrt(i + s);
            }
        } else
            for (int i = 1; i <= n[j]; i++) {
                s = sqrt(i + s);
            }
        cout << fixed << setprecision(5) << s << "\n";
    }
}