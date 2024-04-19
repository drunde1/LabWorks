#include <iostream>
#include"Header.h"


using namespace std;
extern int IN;
extern int OUT;
string fout;

int main()
{	
	interface();
	if (IN == 0)
	{
		consol();
	}
	else
	{
		file();
	}
}