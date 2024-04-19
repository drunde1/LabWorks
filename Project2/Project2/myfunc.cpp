#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int IN;
int OUT;

int main();

void out(double * array, int n)
{
    if (OUT == 0)
    {
        setlocale(0, "");
        cout << "Последовательность: " << endl;
        for (int i = 0; i < n; i++)
            cout << array[i] << " ";
    }
    else
    {
        ofstream fout("out.txt");
        for (int i = 0; i < n; i++)
        {
            fout << array[i] << " ";
        }
        fout.close();
    }
}

int Prov()
{
    setlocale(0, "");
    string p;
    bool flag{ true };

    while (flag)
    {
        cin >> p;
        if ((!p.empty() && p.find_first_not_of("01") == string::npos))
            flag = false;
        else
            cout << "Данные введены некоректно, попробуйте снова : " << endl;
    }
    return stoi(p);
}

void Interface()
{
    setlocale(0, "");

    string a;

    cout << "Ввод с консоли (0) или из файла (1): ";
    IN = Prov();
    cout << "Вывод на консоль (0) или в файл (1): ";
    OUT = Prov();
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
            cout << "Данные введены некоректно, попробуйте снова : " << endl;
    }
    return stoi(p);
}

void main_Program(int n)
{
    double** mtrx;
    double* mass = new double[n];
    mtrx = new double* [n];
    for (int i = 0; i < n; i++)
        mtrx[i] = new double[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mtrx[i][j] = 100.0 * rand() / (float)RAND_MAX;
            if (rand() % 2 == 0)
                mtrx[i][j] = mtrx[i][j] * (-1);
            cout << mtrx[i][j] << "  ";
        }
        cout << endl << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (mtrx[i][i] < 0)
        {
            double v = 0;
            for (int j = 0; j < n; j++)
            {
                if (mtrx[i][j] > 0)
                    v = v + mtrx[i][j];
                else
                    break;
            }
            mass[i] = v;
        }
        else
        {
            double v = 0;
            int j = 0;
            while (mtrx[i][j] < 0)
            {
                j += 1;
            }
            for ( j ; j < n; j++)
            {
                v = v + mtrx[i][j];
            }
            mass[i] = v;
        }
    }
    out(mass, n);
}
void proda()
{
    setlocale(0, "");
    cout << "\nПродолжить? (0 - нет, 1 - да): ";
    int prod = Prov();

    if (prod == 1)
        main();
    else
        exit(0);
}

void consol()
{
    double v = 0;
    srand(time(NULL));
    int n;
    cout << "mat:";
    n = entering();
    main_Program(n);
    proda();
}

void file()
{
    srand(time(NULL));
    string a;
    ifstream sin;
    sin.open("in.txt");
    int n;
    setlocale(0, "");
    sin >> n;
    main_Program(n);
}