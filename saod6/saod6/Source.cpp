#include "iostream"
#include "string"

using namespace std;

struct List
{
	int data;
	List* next;
} *list = NULL, *stack = NULL;

void initialization()
{
	list = new List();
	list->data = -1;
	list->next = nullptr;
}

bool isEmpty()
{
	if (list->next == nullptr)
		return 1;
	else
		return 0;
}

bool isStackEmpty()
{
	if (stack == nullptr)
		return 1;
	else
		return 0;
}

void add_after(int value, int pozition = -1)
{
	List* item = new List();
	List* temp = list;
	while (temp->data != pozition)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	if (temp->data != pozition)
		cout << "Элемента с таким значенем нет.\n";
	else
	{
		item->next = temp->next;
		temp->next = item;
		item->data = value;
	}
	temp = nullptr;
}

void add_before(int value, int pozition)
{
	List* item = new List();
	List* temp = list;
	while (temp->next->data != pozition)
	{
		if (temp->next->next == NULL)
			break;
		
		temp = temp->next;
	}
	if (temp->next->data != pozition)
		cout << "Элемента с таким значенем нет.\n";
	else
	{
		item->next = temp->next;
		temp->next = item;
		item->data = value;
	}
	temp = nullptr;
}
void pop(int value)
{
	List* temp = list;
	while (temp->next->data != value)
	{
		if (temp->next->next == NULL)
			break;
		temp = temp->next;
	}
	if (temp->next->data != value)
		cout << "Элемента с таким значенем нет.\n";
	else
	{
		List* item = temp->next;
		temp->next = temp->next->next;
		item->next = stack;
		stack = item;
	}
	temp = nullptr;
}

void print()
{
	if (isEmpty())
		cout << "Список пуст.\n\n";
	else
	{
		List* temp = list ->next;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << endl;
		temp = nullptr;
	}
}

void print_stack()
{
	if (isStackEmpty())
		cout << "Вспомогательный стек пуст.\n\n";
	else
	{
		List* temp = stack;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << endl;
		temp = nullptr;
	}
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

void menu()
{
	int number, value, comd;
	while (true)
	{
		cout << "1. Вывести состояние списка\n";
		cout << "2. Добавить элемент\n";
		cout << "3. Удалить элемент из списка с сохранением во вспомогатльном стеке\n";
		cout << "4. Вывести состояние вспомогательного стека\n";
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
			if (isEmpty())
			{
				cout << "Введите число:\n";
				value = entering();
				add_after(value);
			}
			else
			{
				cout << "1. Добавить после заданного\n";
				cout << "2. Добавить перед заданным\n";
				number = entering();
				if (number == 1)
				{
					cout << "Задайте число из списка:\n";
					comd = entering();
					cout << "Введите число:\n";
					value = entering();
					add_after(value, comd);
				}
				if (number == 2)
				{
					cout << "Задайте число из списка:\n";
					comd = entering();
					cout << "Введите число:\n";
					value = entering();
					add_before(value, comd);
				}
				else
					cout << "Введите 1 или 2\n";

			}
		}
		else if (number == 3)
		{
			if (!isEmpty())
			{
				cout << "Введите число, которое нужно удалить:\n";
				value = entering();
				pop(value);
			}
			else
				cout << "Список пуст. Удалять нечего\n";
		}
		else if (number == 4)
		{
			cout << "Состояние вспомогательного стека:\n\n";
			print_stack();
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

	delete[] list;
	delete[] stack;
}