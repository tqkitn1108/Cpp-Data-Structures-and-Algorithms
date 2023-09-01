#include <iostream>
#define n 9
using namespace std;
int grid[n][n];
void Print()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << grid[i][j];
        }
    }
}
bool Check(int row, int col, int num)
{
    for (int i = 0; i < n; ++i)
    {
        if (grid[i][col] == num)
            return false;
    }
    for (int j = 0; j < n; ++j)
    {
        if (grid[row][j] == num)
            return false;
    }
    int startrow = row - row % 3, startcol = col - col % 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[startrow + i][startcol + j] == num)
                return false;
        }
    }
    return true;
}
bool SolveSudoku(int row, int col)
{
    int num;
    if (row == n - 1 && col == n)
        return true;
    if (col == n)
    {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
    {
        return SolveSudoku(row, col + 1);
    }
    for (int num = 1; num <= 9; ++num)
    {
        if (Check(row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (s[j + 9 * i] == '.')
                grid[i][j] = 0;
            else
                grid[i][j] = s[j + 9 * i] - '0';
        }
    }
    if (SolveSudoku(0, 0))
    {
        Print();
    }
    return 0;
}