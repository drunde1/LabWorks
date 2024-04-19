#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main(int argc, char** argv);

int to_binary_string(int* mass, int n)
{
    setlocale(0, "");
    int g = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (_Checked_x86_x64_popcount(mass[i]) > 64)
            cout << "Слишком большое число" << endl;
        count = 64 - _Checked_x86_x64_popcount(mass[i]);
        g += count;
        count = 0;
    }

    cout << "Количсетво нулевых битов: " << g << endl;
    return 0;
}