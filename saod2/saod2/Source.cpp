#include <iostream>
#include <string>

using namespace std;
#define SIZE 4
int counter = 0;

struct Queue
{
	int mass[SIZE];
} _queue;

void add(Queue &queue, int value)
{
	queue.mass[counter] = value;
	counter++;
}

int pop(Queue &queue)
{
    int temp = queue.mass[0];
	for(int i = 0; i < counter - 1; i++)
		queue.mass[i] = queue.mass[i + 1];
	queue.mass[counter - 1] = 0;
    counter--;
	return temp ;
}

void print(Queue queue)
{
	for (int i = 0; i < counter; i++)
		cout << queue.mass[i] << endl;
    cout << endl;
}

bool isEmpty(Queue queue)
{
    if (counter == 0)
        return 1;
    else
        return 0;
}

bool isFull(Queue queue)
{
    if (counter == SIZE)
        return 1;
    else
        return 0;
}

int entering()
{
    setlocale(0, "");
    string str;
    while (true)
    {
        cin >> str;
        if (!str.empty() && str.find_first_not_of("0123456789") == string::npos)
            break;
        else
            cout << "������ ������� ����������, ���������� ����� : " << endl;
    }
    return stoi(str);
}

void menu()
{
    int number, value, comd;
    while (true)
    {
        cout << "1. ������� ��������� �������\n";
        cout << "2. �������� ������� � ����� �������\n";
        cout << "3. ������� ������� �� ������ �������\n";
        cout << "0. ��������� ������ ���������\n";
        cout << "������� ����� �������:\n";
        number = entering();

        if (number == 1) 
        { 
            cout << "��������� �������:\n\n";
            print(_queue);
        }
        else if (number == 2) 
        { 
            if (isFull(_queue) != 1)
            {
                cout << "������� �����:\n";
                value = entering();
                add(_queue, value);
            }
            else
                cout << "������� ���������.\n\n";         
        }
        else if (number == 3) 
        { 
            if (!isEmpty(_queue))
                pop(_queue);
            else 
                cout << "������� �����.\n";
            
        }
        else if (number == 0)
            break;
        else
            cout << "����� ������� ���. ��������� ���� �������\n";
    }
}

int main()
{
    setlocale(0, "");
    srand((time_t)time(NULL));
    menu();
    return 0;
}