#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{
    time_t now = time(0); // Thời gian hiện tại tính theo hệ thống

    char *datetime = ctime(&now); // convert sang string

    cout << "The current local date and time is: " << datetime << "\n"; // Giờ địa phương

    tm *gmtm = gmtime(&now);
    datetime = asctime(gmtm);
    cout << "The current UTC date and time is:" << datetime << endl; // Giờ quốc tế

    cout << "Number of sec since 1/1/1970:" << now << endl;

    tm *ltm = localtime(&now);

    // in ra các thành phần của cấu trúc tm struct
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
    cout << "Time: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
    getch();
}