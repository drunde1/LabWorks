#include <iostream>
#include <string>

using namespace std;

#define SIZE 6

struct list
{
	int mass[SIZE];
	int counter;
}*lst;

void initialization()
{
	lst = new list;
	lst->counter = 0;
	for (int i = 0; i < SIZE; i++)
		lst->mass[i] = 0;
}

bool isEmpty()
{
	if (lst->counter == 0)
		return 1;
	else
		return 0;
}

bool isFull()
{
	if (lst->counter == SIZE)
		return 1;
	else
		return 0;
}

bool biggest(int value)
{
	int count = 0;
	for (int i = 0; i < lst->counter; i++)
	{
		if (value < lst->mass[i])
			count++;
	}
	if (count == 0)
		return true;
	else
		return false;
}

void add(int value)
{
	if (!isFull())
	{
		if (lst->counter == 0)
			lst->mass[lst->counter] = value;
		else if(biggest(value))
			lst->mass[lst->counter] = value;
		else
		{
			int pozition = 0;

			while (value >= lst->mass[pozition])
				pozition++;

			int tempmass[6];
			for (int i = 0; i < SIZE; i++)
				tempmass[i] = lst->mass[i];

			lst->mass[pozition] = value;

			for (int i = pozition + 1; i < lst->counter + 1; i++)
				lst->mass[i] = tempmass[i - 1];
		}
		lst->counter++;
	}
}

int pop(int pozition)
{
	if (!isEmpty())
	{
		if (pozition > lst->counter)
		{
			cout << "Элемента с таким номером нет." << endl;
			return -1;
		}
		else
		{
			int val = lst->mass[pozition - 1];
			for (int i = pozition - 1; i < lst->counter; i++)
			{
				lst->mass[i] = lst->mass[i + 1];
			}
			lst->mass[lst->counter - 1] = 0;
			lst->counter--;
			return val;
		}
	}
	else
		return -1;
}

void print()
{
	for (int i = 0; i < lst->counter; i++)
		cout << lst->mass[i] << endl;
	cout << endl;
}

int search(int value)
{
	for (int i = 0; i < lst->counter; i++)
	{
		if (lst->mass[i] == value)
			return i + 1;
	}
	return -1;
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
			cout << "Данные введены некоректно, попробуйте снова : " << endl;
	}
	return stoi(str);
}

void menu()
{
	int number, value, comd;
	while (true)
	{
		cout << "1. Вывести состояние списка\n";
		cout << "2. Добавить элемент\n";
		cout << "3. Удалить элемент\n";
		cout << "4. Поиск элемента\n";
		cout << "0. Завершить работу программы\n";
		cout << "Введите номер команды:\n";
		number = entering();

		if (number == 1)
		{
			cout << "Состояние списка:\n\n";
			print();
		}
		else if (number == 2)
		{
			if (!isFull())
			{
				cout << "Введите число:\n";
				value = entering();
				add(value);
			}
			else
				cout << "Список заполнен.\n\n";
		}
		else if (number == 3)
		{

			if (!isEmpty())
			{
				cout << "Введите элемент, который нужно удалить:\n";
				value = entering();
				if (search(value) == -1)
					cout << "Элемента с таким значением нет." << endl;
				else
					pop(search(value));
			}
			else
				cout << "Список пуст.\n";

		}
		else if (number == 4)
		{
			if (!isEmpty())
			{
				cout << "Введите значение элемента, который нужно найти:" << endl;
				value = entering();
				if (search(value) == -1)
					cout << "Элемента с таким значением нет." << endl;
				else
					cout << "Номер элемента со значением " << value << ": " << search(value) << endl << endl;
			}
			else
				cout << "Список пуст.\n";
			
		}
		else if (number == 0)
			break;
		else
			cout << "Такой команды нет. Повторите ввод команды\n";
	}
}

int main()
{
	setlocale(0, "");
	initialization();
	menu();
	delete[] lst;

	return 0;
}