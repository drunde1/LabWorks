#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main(int argc, char** argv)
{
    setlocale(0, "");
    int* array = new int[argc - 1];
    try
    {
        for (int i = 0; i < argc - 1; i++)
            array[i] = stoull(argv[i + 1]);
        to_binary_string(array, argc - 1);
    }
    catch (const invalid_argument& ia)
    {
        cerr << "Неверно задано значение массива" << endl;
    }
    return 0;
}