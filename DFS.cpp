#include <iostream>
#include <vector>
#include <cstring>

#define ll long long

using namespace std;

ll n, m;               // n đỉnh, m cạnh, đồ thị vô hướng
vector<int> adj[1001]; // adj[x] là vector chứa các đỉnh kề với đỉnh x
bool visited[1001];    // kiểm tra xem đỉnh v đã được thăm hay chưa
int Trace[1001];
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Nếu là đồ thị có hướng thì bỏ dòng "adj[y].push_back(x);"
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]) // vòng lặp for-each trong c++11
    {
        if (!visited[v])
        {
            Trace[v] = u; // Lưu vết đường đi: Đỉnh liền trước v trong đường đi từ S(đỉnh đầu) tới v là u
                          // Mảng này chỉ dùng khi đề yêu cầu tìm đường đi từ đỉnh S tới đỉnh F nào đó
            dfs(v);
        }
    }
}

int main()
{
    input();
    dfs(1);
}
/*
    Sửa lỗi "error: range-based 'for' loops are not allowed in C++98 mode"
    Chạy với dòng : "g++ -std=c++0x -o DFS .\DFS.cpp" thay cho "g++ .\DFS.cpp -o .\DFS"
*/