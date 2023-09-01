#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
int n;
typedef struct DaThuc
{
	double x;
	int bac;
	string ten;
	vector<double> heSoBac;
} DT;

void pressAnyKey()
{
	cout << endl;
	cout << "Bam phim bat ky de tiep tuc!";
	getch();
	system("cls");
}

int main()
{
	vector<DT> dt;
	cout << "\nTa Quang Kien - 20210502 - 2022.2 - 727635:\n";
	cout << "Nhap so luong da thuc:";
	cin >> n;

	while (true)
	{
		cout << "****************************************************\n";
		cout << "Ta Quang Kien - 20210502 - 2022.2 - 727635:\n";
		cout << "**		CHUONG TRINH QUAN LY CAC DA THUC            **\n";
		cout << "**		  1. Nhap cac da thuc, gia tri x         **\n";
		cout << "**		  2. In danh sach da thuc, va gia tri    **\n";
		cout << "**		  0. Thoat                               **\n";
		cout << "****************************************************\n";
		cout << "**       	Nhap lua chon cua ban                **\n";
		int luachon;
		cin >> luachon;
		if (luachon == 1)
		{
			cout << "\nBan da chon nhap DS da thuc!";
			for (int i = 1; i <= n; ++i)
			{
				DT dathuc;
				cout << "\nNhap da thuc thu " << i << ":\n";
				cout << "Ta Quang Kien - 20210502 - 2022.2 - 727635:\n";
				cout << "Nhap ten da thuc: ";
				cin >> dathuc.ten;
				cout << "\nNhap bac: ";
				cin >> dathuc.bac;
				cout << "\nNhap x: ";
				cin >> dathuc.x;
				for (int j = dathuc.bac; j >= 0; --j)
				{
					cout << "\nHe so bac " << j << ":";
					double heso;
					cin >> heso;
					dathuc.heSoBac.push_back(heso);
				}
				reverse(dathuc.heSoBac.begin(), dathuc.heSoBac.end());
				dt.push_back(dathuc);
			}
			cout << "---------------------------------------------------------" << endl;
			cout << "Ban da nhap thanh cong!" << endl;
			pressAnyKey();
		}
		else if (luachon == 2)
		{
			cout << "\nBan da chon xuat DS da thuc, Gia tri da thuc!\n";
			cout << "Ta Quang Kien - 20210502 - 2022.2 - 727635:\n";
			cout << "____________________________________________\n";
			for (DT v : dt)
			{
				cout << "Da thuc: " << v.ten << "(x) = ";
				for (int j = v.bac; j >= 0; --j)
				{
					if (j == 0)
					{
						if (v.heSoBac[0] != 0)
							cout << v.heSoBac[0];
					}
					else
					{
						if (v.heSoBac[j] != 0)
						{
							cout << v.heSoBac[j] << "*x";
							if (j != 1)
								cout << "^" << j;
							if (v.heSoBac[j - 1] > 0)
								cout << " + ";
						}
					}
				}
				double giatri = 0;
				for (int i = v.bac; i >= 0; i--)
				{
					if (i == 0)
					{
						giatri += v.heSoBac[i];
					}
					else
					{
						giatri += v.heSoBac[i] * pow(v.x, i);
					}
				}
				cout << "\nGia tri Da thuc: F(" << v.x << ") = ";
				cout << fixed << setprecision(2) << giatri << "\n";
				cout << fixed << setprecision(0);
			}
			cout << "____________________________________________\n";
			pressAnyKey();
		}
		else
		{
			cout << "\nBan da chon thoat chuong trinh!";
			getch();
			return 0;
		}
	}
	return 0;
}
