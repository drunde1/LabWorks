#include <windows.h>
//#include <windowsx.h>
//#include <winuser.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

using namespace std;

struct Queue
{
    Queue* next;
    char data;
   }*top = NULL, *last = NULL;

inline void initialization()
{
    top = new Queue;
    top->next = NULL;
    last = top;
}

bool isEmpty()
{
    if (top->next == NULL)
        return 1;
    else
        return 0;
}

void add(char value)
{
    Queue* item = new Queue;
    item->data = value;
    item->next = NULL;
    last->next = item;
    last = item;
}

char pop()
{
    if (!isEmpty())
    {
        Queue* temp = top;
        top = top->next;
        return temp->data;
        delete[] temp;
    }
    else
    {
        cout << "Очередь пуста.\n" << endl;
        return ' ';
    }
}

void Randomize()
{
    srand(time(0));
    int number = rand() % 3 + 1;
    if ((rand() % 100) % 2 == 0)
    {
        for (int i = 0; i < number; i++)
            add(static_cast<char>(65 + rand() % 26));
    }
    else
    {
        for (int i = 0; i < number; i++)
        {
            if (!isEmpty()) { pop(); }
        }
    }
}

void print()
{
    if (isEmpty())
        cout << "Очередь пуста." << endl;
    else
    {
        Queue* current = top;
        while (current != NULL)
        {
            cout << current->data;
            current = current->next;
        }
    }
    cout << endl << endl;
}

int main()
{
    setlocale(0, "");
    initialization();
    do
    {
        Sleep(500);
        system("cls");
        Randomize();
        cout << "Для остановки нажмите клавишу Esc" << endl;
        print();
        
        if (GetAsyncKeyState(0x1B))
        {
            _getch();
            break;
        }
    
    } while (true);
 
    return 0;
}
