#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    system("cls");
    cout << "\n\t===================WELCOME===================";
    cout << "\n\t<<<<<<<<<<<<<<<<<<<<(^_^)>>>>>>>>>>>>>>>>>>>>";
    cout << "\n\t<<                                         >>";
    cout << "\n\t<<<              Kien Ta Quang            >>>";
    cout << "\n\t<<                                         >>";
    char password[20];
    char ch[100];
    do
    {
        cout << "\n\n| ENTER YOUR PASSWORD |\n\n";
        string phrase = "enter your password";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
        gets(password);
        STARTUPINFO StartInfo = {0};
        PROCESS_INFORMATION ProcessInfo = {0};
        if (strcmp(password, "taquangkien") == 0)
        {
            string phrase = "Correct password";
            string command = "espeak \"" + phrase + "\"";
            const char *charCommand = command.c_str();
            system(charCommand);
            do
            {
                cout << "\n How can I help you boss ?\n\n ";
                string phrase = "How can I help you boss";
                string command = "espeak \"" + phrase + "\"";
                const char *charCommand = command.c_str();
                system(charCommand);
                cout << "Your query: ";
                gets(ch);
                cout << "\nHere is the result: ";
                if (strcmp(ch, "What's your name") == 0 || strcmp(ch, "Who are you") == 0 || strcmp(ch, "your name") == 0)
                {
                    cout << "I'm a virtual assistant";
                    string phrase = "I'm a virtual assistant";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                }
                else if (strcmp(ch, "bye") == 0 || strcmp(ch, "goodbye") == 0 || strcmp(ch, "exit") == 0)
                {
                    cout << "Goodbye sir, have a nice day!!";
                    string phrase = "Goodbye sir, have a nice day";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    exit(0);
                }
                else if (strcmp(ch, "open notepad") == 0)
                {
                    cout << "\nopening notepad.....\n";
                    CreateProcess(TEXT("C:\\Windows\\notepad.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &StartInfo, &ProcessInfo);
                }
                else if (strcmp(ch, "open coccoc") == 0)
                {
                    cout << "\nopening coccoc.....\n";
                    string phrase = "opening coccoc";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    system("start https://www.coccoc.com");
                }
                else if (strcmp(ch, "open youtube") == 0)
                {
                    cout << "\nopening youtube.....\n";
                    string phrase = "opening youtube";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    system("start https://www.youtube.com");
                }
                else if (strcmp(ch, "open luyencode") == 0)
                {
                    cout << "\nopening luyencode.....\n";
                    string phrase = "opening luyencode";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    system("start https://www.luyencode.net");
                }
                else
                {
                    cout << "Sorry I could not understand your query, please try again !!!";
                    string phrase = "Sorry I could not understand your query, please try agai";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                }

            } while (1);
        }
        else
        {
            cout << "incorrect password\n";
            string phrase = "Incorrect password";
            string command = "espeak \"" + phrase + "\"";
            const char *charCommand = command.c_str();
            system(charCommand);
        }
    } while (true);

    return 0;
}