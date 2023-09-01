#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int main()
{
    system("cls"); // lệnh xóa màn hình
    for (int i = 1; i <= 50; ++i)
    {
        system("cls");
        cout << "\n\t<<<<<<<<<<<<<<<<<<<<(^_^)>>>>>>>>>>>>>>>>>>>>";
        cout << "\n\t<<                                         >>";
        cout << "\n\t<<<          Hello Kien Ta Quang          >>>";
        cout << "\n\t<<                                         >>";
        cout << "\n\t<<<<<<<<<<<<<<<<<<<<(^:^)>>>>>>>>>>>>>>>>>>>>";
        cout << "\n\n\t        LOANDING " << 2 * i << "% \n\t       ";
        for (int j = 1; j <= i; ++j)
        {
            cout << (char)178;
        }
        if (i > 1 && i < 20)
            cout << "\n\n\t\tCreating temporary files";
        else if (i > 20 && i < 40)
            cout << "\n\n\t\tAccessing main memory";
        else if (i > 40 && i < 48)
            cout << "\n\n\t\tAccessing cache";
        else
            cout << "\n\n\t\tComplete.Press Enter to Continue ";
        Sleep(150 - i * 3);
    }
    getch(); // Hàm trong thư viện <conio.h>, Thay cho system("Pause")
}