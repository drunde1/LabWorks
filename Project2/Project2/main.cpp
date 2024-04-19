#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)
#include "header.h"

using namespace std;
extern int IN;
extern int OUT;

int main()
{
    Interface();
    if (IN == 0)
        consol();
    else
        file();
}