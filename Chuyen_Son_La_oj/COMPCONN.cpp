// Code by Ta Quang Kien
// 6/10/2022
#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();

using namespace std;

ll n, m, c = 0, a[1001], idx = 0;
vector<int> adj[1001];
bool visited[1001], visited2[1001];
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u)
{
    a[idx++] = u;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}
void dfs2(int u)
{
    visited2[u] = true;
    for (int v : adj[u])
    {
        if (!visited2[v])
        {
            dfs2(v);
        }
    }
}
int main()
{
    fast_io;
    input();
    for (int i = 1; i <= n; ++i)
    {
        if (!visited2[i])
        {
            dfs2(i);
            c++;
        }
    }
    cout << c << "\n";
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            cout << idx;
            sort(a, a + idx);
            for (int j = 0; j < idx; ++j)
            {
                cout << " " << a[j];
            }
            cout << "\n";
            idx = 0;
        }
    }
}
/*
    Sửa lỗi "error: range-based 'for' loops are not allowed in C++98 mode"
    Chạy với dòng : "g++ -std=c++0x -o DFS .\DFS.cpp" thay vì "g++ .\DFS.cpp -o .\DFS"
*/