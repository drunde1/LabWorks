#include <iostream>
#include"Header.h"
using namespace std;

int IN;

int main()
{
	setlocale(0, "");
	cout << "¬вод с консоли (0) или с файла (1): ";
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