#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int IN;
int OUT;
int main();

int Prov()
{
	setlocale(0, "");
	string p;
	bool F{ true };

	while (F)
	{
		cin >> p;
		if ((!p.empty() && p.find_first_not_of("01") == string::npos))
			F = false;
		else
			cout << "������ ������� ����������, ���������� ����� : " << endl;
	}
	return stoi(p);
}

void interface()
{
	string a;
	setlocale(0, "");
	cout << "���� � ������� (0) ��� � ����� (1):";
	IN = Prov();
	cout << "����� � ������� (0) ��� � ���� (1):";
	OUT = Prov();
}

void proda()
{
	setlocale(0, "");
	cout << "����������? (0 - ���, 1 - ��): ";
	int pr = Prov();

	if (pr == 1)
		main();
	else
		exit(0);
}


int entering()
{
	setlocale(0, "");
	string p;
	bool F{ true };

	while (F)
	{
		cin >> p;
		if (!p.empty() && p.find_first_not_of("0123456789") == string::npos)
			F = false;
		else
			cout << "������ ������� ����������, ���������� ����� : " << endl;
	}
	return stoi(p);
}

float entering1()
{
	setlocale(0, "");
	float a;
	while (true)
	{
		cin >> a;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ ������� ����������, ���������� ����� : " << endl;
		}
		else
			break;
	}
	return a;
}

void consol()
{
	int n;
	float a;
	float p;
	int t{ 2 };
	setlocale(0, "");
	cout << "������� n:";
	n = entering();
	cout << "������� ����� a[0]:";
	a = entering1();
	p = a;
	float c = a;
	for (int i = 1; i < n; i++)
	{
		cout << "������� ����� a" << "[" << i << "]:";
		a = entering1();
		if ((a <= p) || ((t+1) * a <= (t) * p))
		{
			if (OUT == 0)
				cout << "������������������ �� �������� ������������!" << endl;
			else
			{
				ofstream fout("out.txt");
				fout << "������������������ �� �������� ������������!";
				fout.close();
			}
			proda();
			exit(0);
		}
		else
		{
			p = a;
			t += 1;

		}
		if (i == n-1)
		{
			if (p >= 2 * c)
			{
				if (OUT == 0)
					cout << "������������������ �� �������� ������������!" << endl;
				else
				{
					ofstream fout("out.txt");
					fout << "������������������ �� �������� ������������!";
					fout.close();
				}
				proda();
				exit(0);
			}
		}
	}
	if (OUT == 0)
		cout << "������������������ ������������!" << endl;
	else
	{
		ofstream fout("out.txt");
		fout << "������������������ ������������!";
		fout.close();
	}
	proda();
}

void file()
{
	string a;
	ifstream creat;
	creat.open("in.txt");
	while (true)
	{
		int n;
		float a;
		float p;
		int t{ 2 };
		setlocale(0, "");
		creat >> n;
		creat >> a;
		p = a;
		float c = a;
		for (int i = 1; i < n; i++)
		{
			creat >> a;
			if ((a <= p) || ((t + 1) * a <= (t)*p))
			{
				if (OUT == 0)
				{
					cout << "������������������ �� �������� ������������!!!!";
				}
				else
				{
					ofstream fout("out.txt");
					fout << "������������������ �� �������� ������������!";
					fout.close();
				}
				exit(0);
			}
			else
			{
				p = a;
				t += 1;

			}
			if (i == n - 1)
			{
				if (p >= 2 * c)
				{
					if (OUT == 0)
					{
						cout << "������������������ �� �������� ������������!";
					}
					else
					{
						ofstream fout("out.txt");
						fout << "������������������ �� �������� ������������!";
						fout.close();
					}
					exit(0);
				}
			}
		}
		if (OUT == 0)
		{
			cout << "������������������ ������������!";
		}
		else
		{
			ofstream fout("out.txt");
			fout << "������������������ ������������!";
			fout.close();
		}
		break;
	}
}