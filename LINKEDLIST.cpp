/* Đề bài:Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. 
Tiếp theo nhập hai số nguyên a và b. Hãy thay đổi giá trị của những phần tử có giá trị a thành giá trị b. In ra màn hình danh sách đó, sau một phần tử có đúng một khoảng trắng.*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *CreateNode(int x)
{
    node *tmp = new node;
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
node *AddNode(node *p, int x)
{
    node *tmp = CreateNode(x);
    p->next = tmp;
    return tmp;
}
void PrintList(node *l)
{
    node *p = l;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void ChangeValue(node *l, int a, int b)
{
    node *p = l;
    while (p != NULL)
    {
        if (p->data == a)
        {
            p->data = b;
        }
        p = p->next;
    }
}
int main()
{
    int n, x, a, b;
    cin >> n >> x;
    node *l = CreateNode(x);
    node *p = l;
    for (int i = 1; i < n; ++i)
    {
        cin >> x;
        p = AddNode(p, x);
    }
    cin >> a >> b;
    ChangeValue(l, a, b);
    PrintList(l);
}