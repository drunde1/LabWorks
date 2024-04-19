#include <iostream>
#include <string>

using namespace std;

struct Stack
{
	int data;
	Stack* next;
	Stack(int value, Stack* pointer = NULL)
	{
		data = value;
		next = pointer;
	}
} *stack = NULL, * secstack = NULL;

bool isEmpty(Stack* astack)
{
	if (astack == NULL)
		return 1;
	else
		return 0;
}

Stack* add(Stack* astack, int value)
{
	Stack* item = new Stack(value, astack);
	astack = item;
	return astack;
}

Stack* add_some_rand(Stack* astack)
{
	int count;
	cout << "������� ����� ��������?\n";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		astack = add(astack, rand());
	}
	return astack;
}

Stack* pop(Stack* astack)
{
	if (!isEmpty(astack))
	{
		Stack* temp = astack;
		astack = astack->next;
		delete[] temp;
	}
	return astack;
}

void print(Stack* astack)
{
	if (isEmpty(astack))
		cout << "���� ����." << endl;
	else
	{
		Stack* current = astack;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	cout << endl;
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
			cout << "������ ������� ����������, ���������� ����� : " << endl;
	}
	return stoi(p);
}

void Transfer(Stack*& first, Stack*& second)
{
	if (!isEmpty(first))
	{
		Stack* temp = first;
		first = first->next;
		temp->next = second;
		second = temp;
	}
}

void menu()
{
	int number, value, comd;
	while (true)
	{
		cout << "1. ������� ��������� �������� �����\n";
		cout << "2. �������� ������� � ������� ����\n";
		cout << "3. ������� ������� �� �������� �����\n";
		cout << "4. �������� ��������� ��������� ����� � ������� ����\n";
		cout << "5. ������� ��������� ���������������� �����\n";
		cout << "0. ��������� ������ ���������\n";
		cout << "������� ����� �������:\n";
		number = entering();

		if (number == 1)
		{
			cout << "��������� �����:\n\n";
			print(stack);
		}
		else if (number == 2)
		{
			cout << "1. ������� ����� ������� \n2. ����� � ������� ���������������� �����\n������� ����� �������:\n ";
			comd = entering();
			if (comd == 1)
			{
				cout << "������� ����� �����: \n";
				value = entering();
				stack = add(stack, value);
			}
			else if (comd == 2)
			{
				if (!isEmpty(secstack))
				{
					Transfer(secstack, stack);
				}
				else cout << "��������������� ���� ����.\n";
			}
			else
				cout << "������ �����. ��������� ���� �������\n";
		}
		else if (number == 3)
		{
			if (!isEmpty(stack))
			{
				cout << "�������� �������: \n 1. ������� ������� � ������ ������������� ������ \n 2. �������� ��� � ������� ���������������� ����� ��������� ���������\n������� ����� �������:\n ";
				comd = entering();
				if (comd == 1)
				{
					stack = pop(stack);
				}
				else if (comd == 2)
				{
					if (stack != NULL)
					{
						Transfer(stack, secstack);
					}
					else
					{
						cout << "���� ����.\n";
					}
				}
				else {
					cout << "������ �����. ��������� ���� �������\n";
				}
			}
			else {
				cout << "���� ����. ������� ������\n";
			}
		}
		else if (number == 4)
			stack = add_some_rand(stack);
		else if (number == 5)
		{
			cout << "��������� ���������������� ����� ��������� ���������:\n\n";
			print(secstack);
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
	stack = NULL;
	secstack = NULL;
	srand((time_t)time(NULL));
	menu();
	return 0;
}