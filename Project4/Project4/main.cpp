#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
 
using namespace std;

int main()
{
    int* mass = Interface();
    if (mass[0] == 0)
        consol( mass[1]);
    else
        file( mass[1]);
}
