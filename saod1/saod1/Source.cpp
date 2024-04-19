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
	cout << "Сколько чисел добавить?\n";
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
		cout << "Стек пуст." << endl;
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
			cout << "Данные введены некоректно, попробуйте снова : " << endl;
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
		cout << "1. Вывести состояние главного стека\n";
		cout << "2. Добавить элемент в главный стек\n";
		cout << "3. Удалить элемент из главного стека\n";
		cout << "4. Добавить несколько рандомных чисел в главный стек\n";
		cout << "5. Вывести состояние вспомогательного стека\n";
		cout << "0. Завершить работу программы\n";
		cout << "Введите номер команды:\n";
		number = entering();

		if (number == 1)
		{
			cout << "Состояние стека:\n\n";
			print(stack);
		}
		else if (number == 2)
		{
			cout << "1. Создать новый элемент \n2. Выбор с вершины вспомогательного стэка\nВведите номер команды:\n ";
			comd = entering();
			if (comd == 1)
			{
				cout << "Введите целое число: \n";
				value = entering();
				stack = add(stack, value);
			}
			else if (comd == 2)
			{
				if (!isEmpty(secstack))
				{
					Transfer(secstack, stack);
				}
				else cout << "Вспомогательный стек пуст.\n";
			}
			else
				cout << "Ошибка ввода. Повторите ввод команды\n";
		}
		else if (number == 3)
		{
			if (!isEmpty(stack))
			{
				cout << "Уточните команду: \n 1. Удалить элемент с полным освобождением памяти \n 2. Включить его в вершину вспомогательного стека удаленных элементов\nВведите номер команды:\n ";
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
						cout << "Стек пуст.\n";
					}
				}
				else {
					cout << "Ошибка ввода. Повторите ввод команды\n";
				}
			}
			else {
				cout << "Стек пуст. Удалять нечего\n";
			}
		}
		else if (number == 4)
			stack = add_some_rand(stack);
		else if (number == 5)
		{
			cout << "Состояние вспомогательного стека удаленных элементов:\n\n";
			print(secstack);
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
	stack = NULL;
	secstack = NULL;
	srand((time_t)time(NULL));
	menu();
	return 0;
}