#include "iostream"
#include "string"

using namespace std;

struct List
{
	int data;
	List* next;
	List* prev;
}*list = NULL;

void initialization()
{
	list = new List();
	list->data = -1;
	list->next = list;
	list->prev = list;
}

bool isEmpty()
{
	if (list->next == list)
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
		if (temp->next == list)
			break;
		temp = temp->next;
	}
	if (temp->data != pozition)
		cout << "Элемента с таким значенем нет.\n";
	else
	{
		item->next = temp->next;
		item->prev = temp;
		item->next->prev = item;
		temp->next = item;
		item->data = value;
	}
	temp = nullptr;
	delete[] temp;
}

void add_before(int value, int pozition)
{
	List* item = new List();
	List* temp = list;
	while (temp->next->data != pozition)
	{
		if (temp->next->next == list)
			break;

		temp = temp->next;
	}
	if (temp->next->data != pozition)
		cout << "Элемента с таким значенем нет.\n";
	else
	{
		item->next = temp->next;
		item->prev = temp;
		item->next->prev = item;
		temp->next = item;
		item->data = value;
	}
	temp = nullptr;
	delete[] temp;
}

int pop(int value)
{
	int i = 0;
	List* temp = list;
	while (temp->next->data != value)
	{
		if (temp->next->next == list)
			break;
		temp = temp->next;
	}
	if (temp->next->data != value)
		cout << "Элемента с таким значенем нет.\n";
	else
	{
		List* temp1 = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		i = temp1->data;
		delete[] temp1;
	}
	temp = nullptr;
	//delete[] temp;
	return i;
}

List* search(int value, int direction)
{
	List* temp = nullptr;
	if (direction == 1)
	{
		temp = list->next;
		while (temp->data != value)
		{
			if (temp->next == list)
				return nullptr;
			temp = temp->next;
		}
		return temp;
	}
	else if (direction == 2)
	{
		temp = list->prev;
		while (temp->data != value)
		{
			if (temp->prev == list)
				return nullptr;
			temp = temp->prev;
		}
		return temp;
	}

}

void print(int direction)
{
	if (isEmpty())
		cout << "Список пуст.\n\n";
	else
	{
		List* temp;
		if (direction == 1)
		{
			temp = list->next;
			while (temp != list)
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
		else if (direction == 2)
		{
			temp = list->prev;
			while (temp != list)
			{
				cout << temp->data << endl;
				temp = temp->prev;
			}
		}
		cout << endl;
		temp = nullptr;
		delete[] temp;
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
		cout << "3. Удалить элемент\n";
		cout << "4. Поиск элемента\n";
		cout << "0. Завершить работу программы\n";
		cout << "Введите номер команды:\n";
		number = entering();

		if (number == 1)
		{
			cout << "1. В прямом направлении\n";
			cout << "2. В обратном направлении\n";
			comd = entering();
			cout << endl;
			if (comd == 1)
				print(1);
			else if (comd == 2)
				print(2);
			else
				cout << "Такой команды нет. Введите 1 или 2.\n\n";
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
			cout << "1. В прямом направлении\n";
			cout << "2. В обратном направлении\n";
			comd = entering();
			cout << "Введите значение:\n";
			value = entering();
			if (comd == 1)
			{
				if (search(value, 1) == nullptr)
					cout << "Элемента с таким значением нет.\n\n";
				else if (search(value, 1)->prev == list)
					cout << "Элемент " << value << " находится в начале списка" << endl << endl;
				else if (search(value, 1)->next == list)
					cout << "Элемент " << value << " находится в конце списка" << endl << endl;
				else
					cout << "Элемент " << value << " находится между " << search(value, 1)->prev->data << " и " << search(value, 1)->next->data << endl << endl;
			}
			else if (comd == 2)
			{
				if (search(value, 2) == nullptr)
					cout << "Элемента с таким значением нет.\n\n";
				else if (search(value, 1)->prev == list)
					cout << "Элемент " << value << " находится в начале списка" << endl << endl;
				else if (search(value, 1)->next == list)
					cout << "Элемент " << value << " находится в конце списка" << endl << endl;
				else
					cout << "Элемент " << value << " находится между " << search(value, 2)->prev->data << " и " << search(value, 2)->next->data << endl << endl;
			}
			else
				cout << "Такой команды нет. Введите 1 или 2.\n\n";
			
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
}