// 23/10/2022
#include <iostream>

#define ll long long
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie();               \
    cout.tie();
#define FORUP(i, a, b) for (int i = a; i <= b; ++i)
#define nmax 100005
const ll amin = -(1e9 + 5);

using namespace std;
ll n, Q;

struct Node // Kiểu dữ liệu cho 1 nút của ST
{
    int lazy; // giá trị với ý nghĩa, tất cả các phần tử trong đoạn [l,r] mà nút id quản lý đều được cộng thêm ST[id].lazy
              // ST[id].lazy!=0 nghĩa là node id có pending lazy update, phải update nút id và đẩy lazy xuống các nút con
    int val;  // ST[id].val là giá trị lớn nhất của phần tử nằm trong đoạn [l,r] mà nút id quản lý
} ST[nmax * 4];
// Nếu nút id đang xét còn có giá trị được thêm vào chưa xét đến (từ các truy vấn cập nhật xảy ra trước đó, mà chưa được cập nhật hết),
// ta buộc phải cập nhật nó trước khi lấy giá trị hoặc tiếp tục đệ quy sâu hơn.
// Sau khi cập nhật xong nút id, ta phải đẩy giá trị lazy ở nút id xuống các con của nó để tiếp tục cập nhật và đặt lại lazy của nút id về 0.
void Down(int id, int l, int r)
{
    int t = ST[id].lazy;
    ST[id].val += t;
    if (l != r) // Nếu nút id không phải là nút lá thì ta đẩy giá trị lazy xuống các con của nó
    {
        ST[id * 2].lazy += t;
        ST[id * 2 + 1].lazy += t;
    }
    ST[id].lazy = 0;
}

void update(int id, int val, int l, int r, int u, int v)
{
    if (ST[id].lazy != 0)
    {
        Down(id, l, r);
    }
    if (v < l || u > r)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        ST[id].val += val;
        if (l != r)
        {
            ST[id * 2].lazy += val;
            ST[id * 2 + 1].lazy += val;
        }
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, val, l, m, u, v);
    update(id * 2 + 1, val, m + 1, r, u, v);
    ST[id].val = max(ST[id * 2].val, ST[id * 2 + 1].val);
}
int get(int id, int l, int r, int u, int v)
{
    if (ST[id].lazy != 0)
    {
        Down(id, l, r);
    }
    if (v < l || u > r)
    {
        return amin;
    }
    if (u <= l && v >= r)
    {
        return ST[id].val;
    }
    int m = (l + r) / 2;
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main()
{
    fast_io;
    cin >> n >> Q;
    while (Q > 0)
    {
        ll k, u, v, val;
        cin >> k;
        if (k == 0)
        {
            cin >> u >> v >> val;
            update(1, val, 1, n, u, v);
        }
        else
        {
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << "\n";
        }
        Q--;
    }
}