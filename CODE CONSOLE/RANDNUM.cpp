#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main()
{
    // Khởi tạo bộ số ngẫu nhiên, dùng thời gian thực của hệ thống nên sẽ không bị trùng
    srand(time(NULL)); // NULL can be replaced by 0

    int a = rand(); // Hàm này trả về số ngẫu nhiên trong [0;RAND_MAX]
    cout << a << endl;

    // Random trong 1 khoảng, ví dụ 1-100
    cout << rand() % 100 + 1 << endl;
}