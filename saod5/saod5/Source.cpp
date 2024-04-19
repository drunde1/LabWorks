#include <iostream>
#include <string>

using namespace std;

#define SIZE 6
#define size 2
#define data 0
#define index 1

int* list[SIZE];

void init()
{
	for (int i = 0; i < SIZE; i++)
		list[i] = new int[size];
	list[0][data] = -1;
	list[0][index] = 0;
	for (int i = 1; i < SIZE; i++)
		list[i][index] = -1;
}

void clean()
{
	for (int i = 0; i < SIZE; i++)
	{
		list[i][data] = 0;
		list[i][index] = 0;
		list[i] = nullptr;
	}
}

int searchFreeItem()
{
	for (int i = 1; i < SIZE; i++)
	{
		if (list[i][index] == -1)
			return i;
	}
	return 0;
}

bool isFull()
{
	if (searchFreeItem() == 0)
		return 1;
	else
		return 0;
}

bool isEmpty()
{
	for (int i = 1; i < SIZE; i++)
	{
		if (list[i][index] != -1)
			return 0;
	}
	return 1;
}

int search(int value)
{
	if (!isEmpty())
	{
		int i = 0;
		do
		{
			i = list[i][index];
			if (list[i][data] == value)
				return i;
		} while (i != 0);
	}
	else return -1;
}

void add_after(int value, int pozition = -1)
{
	if (!isFull())
	{
		int i = 0;
		while (list[i][data] != pozition)
		{
			i = list[i][index];
			if (list[i][data] == -1)
				break;
		}
		if (list[i][data] != pozition)
			cout << "�������� � ����� �������� ���.\n";
		else
		{
			int tempindex = list[i][index];
			list[i][index] = searchFreeItem();
			list[list[i][index]][index] = tempindex;
			list[list[i][index]][data] = value;
		}
	}
	else
		cout << "��������� ������!\n\n";
}

void add_before(int value, int pozition)
{
	if (!isFull())
	{
		int i = 0;
		while (list[list[i][index]][data] != pozition)
		{
			if (list[list[i][index]][data] == -1)
				break;
			i = list[i][index];
		}
		if (list[list[i][index]][data] != pozition)
			cout << "�������� � ����� �������� ���.\n";
		else
		{
			int tempindex = list[i][index];
			list[i][index] = 0;
			list[i][index] = searchFreeItem();
			list[list[i][index]][index] = tempindex;
			list[list[i][index]][data] = value;
		}
	}
	else
		cout << "��������� ������!\n\n";
}

int pop(int value)
{
	if (!isEmpty())
	{
		int pozition = search(value);
		if (pozition == -1)
		{
			cout << "������ �������� ���." << endl;
			return -1;
		}
		else
		{
			int i = 0;
			while (list[i][index] != pozition)
				i = list[i][index];
			list[i][index] = list[pozition][index];
			list[pozition][index] = -1;
			list[pozition][data] = 0;
		}
	}
	else
	{
		cout << "������� ������!\n\n";
		return -1;
	}
}

void print()
{
	int i = 0;
	do
	{
		i = list[i][index];
		if (i == 0)
			break;
		cout << list[i][data] << endl;

	} while (true);
	cout << endl;
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
		cout << "1. ������� ��������� ������\n";
		cout << "2. �������� �������\n";
		cout << "3. ������� �������\n";
		cout << "4. ����� ��������\n";
		cout << "0. ��������� ������ ���������\n";
		cout << "������� ����� �������:\n";
		number = entering();

		if (number == 1)
		{
			if (isEmpty())
				cout << "������ ����." << endl << endl;
			else
			{
				cout << "��������� ������:\n\n";
				print();
			}
		}
		else if (number == 2)
		{
			if (!isFull())
			{
				if (isEmpty())
				{
					cout << "������� �����:\n";
					value = entering();
					add_after(value);
				}
				else
				{
					cout << "1. �������� ����� ���������\n";
					cout << "2. �������� ����� ��������\n";
					number = entering();
					if (number == 1)
					{
						cout << "������� ����� �� ������:\n";
						comd = entering();
						cout << "������� �����:\n";
						value = entering();
						add_after(value, comd);
					}
					if (number == 2)
					{
						cout << "������� ����� �� ������:\n";
						comd = entering();
						cout << "������� �����:\n";
						value = entering();
						add_before(value, comd);
					}
					else
						cout << "������� 1 ��� 2\n";

				}
			}
			else
				cout << "������ ��������.\n\n";
		}
		else if (number == 3)
		{

			if (!isEmpty())
			{
				cout << "������� �������, ������� ����� �������:\n";
				value = entering();
				if (search(value) == -1)
					cout << "�������� � ����� ��������� ���." << endl;
				else
					pop(value);
			}
			else
				cout << "������ ����.\n";

		}
		else if (number == 4)
		{
			if (!isEmpty())
			{
				cout << "������� �������� ��������, ������� ����� �����:" << endl;
				value = entering();
				if (search(value) == -1)
					cout << "�������� � ����� ��������� ���." << endl;
				else if (list[search(value)][index] == 0)
					cout << "������� " << value << " ��������� � ����� ������" << endl << endl;
				else
					cout << "������� " << value << " ��������� ����� ��������� " << list[list[search(value)][index]][data] << endl << endl;
			}
			else
				cout << "������ ����.\n";

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
	init();
	menu();
	clean;
	return 0;
}