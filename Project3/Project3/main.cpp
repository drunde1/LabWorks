#include <iostream>
#include"Header.h"
using namespace std;

int IN;

int main()
{
	setlocale(0, "");
	cout << "���� � ������� (0) ��� � ����� (1): ";
	IN = Prov();
	if (IN == 0)
	{
		consol();
	}
	else
	{
		file();
	}
}