#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int IN;
int OUT;

int main();

int Prov()
{
	setlocale(0, "");
	string p;
	bool flag{ true };

	while (flag)
	{
		cin >> p;
		if (!p.empty() && p.find_first_not_of("01") == string::npos && p.length() == 1)
			flag = false;
		else
			cout << "������ ������� ����������, ���������� ����� : " << endl;
	}
	return stoi(p);
}

void proda()
{
	setlocale(0, "");
	cout << "����������? (0 - ���, 1 - ��): ";
	int prod = Prov();

	if (prod == 1)
		main();
	else
		exit(0);
}

void out(char str[], int n, int g)
{
	if (g == 0)
	{
		setlocale(0, "");
		cout << "���� ������: " << endl;
		for (int i = 0; i < n; i++)
			cout << str[i];
		cout << endl;
	}
	else
	{
		setlocale(0, "");	
		cout << "�������� ���� ��� ������ ����������� ������ ��������� [~`rez`out.txt]:" << endl;
		string path;
		getline(cin, path);
		if (path.empty())
		{
			ofstream fout("out.txt");
			for (int i = 0; i < n; i++)
				fout << str[i];
			fout.close();
		}
		else
		{
			ofstream fout(path, ios::binary);
			for (int i = 0; i < n; i++)
				fout << str[i];
			fout.close();
		}
		
	}
}

void consol( int g  )
{
	cout << "������� ������:" << endl;
	string s;
	cin >> s;
	cin.ignore();
	string st = "abcd";
	for (size_t k = s.find(st); k != s.npos; k = s.find(st, k))
	{
		s.erase(k, 4);
	}
	char* str = new char[s.length()];
	for (int i = 0; i < s.length(); i++)
		str[i] = s[i];
	out(str, s.length(), g);
	proda();
}

void file( int g)
{
	
	string s;
	setlocale(0, "");
	cout << "�������� ���� ��� ����� ������ [~`rez`in.txt]:" << endl;
	string path;
	cin.get();
	getline(cin, path);
	if (path.empty())
		path = "C:\\Users\\andre\\source\\repos\\Project4\\Project4\\in.txt";
	ifstream sin(path);
	sin >> s;
	sin.close();
	string st = "abcd";
	for (size_t k = s.find(st); k != s.npos; k = s.find(st, k))
	{
		s.erase(k, 4);
	}
	char* str = new char[s.length()];
	for (int i = 0; i < s.length(); i++)
		str[i] = s[i];
	out(str, s.length(), g);
}

int *Interface()
{
	static int inout[2];
	setlocale(0, "");
	string a;
	cout << "���� � ������� (0) ��� �� ����� (1): ";
	inout[0] = Prov();
	cout << "����� �� ������� (0) ��� � ���� (1): ";
	inout[1] = Prov();
	return inout;
}