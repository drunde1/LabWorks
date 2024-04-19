#include <iostream>
#include <string>

using namespace std;

struct MyList
{
	int data;
	MyList* next;
	MyList()
	{
		data = 0;
		next = nullptr;
	}
};

struct MainList 
{
	MyList* list;
	MainList* next;
	string name;
	MainList()
	{
		list = nullptr;
		next = nullptr;
	}
}*List;

void initialization()
{
	List = new MainList();
	List->name = "Head";
}

bool isMainEmpty()
{
	if (List->list == nullptr && List->next == nullptr)
		return 1;
	else
		return 0;
}

bool isEmpty(MainList* pointer)
{
	if (pointer->list == nullptr)
		return 1;
	else
		return 0;
}

void addToList_after(string Name, string pozition = "Head")
{
	MainList* item = new MainList();
	MainList* temp = List;
	while (temp->name != pozition)
	{
		if (temp->next == nullptr)
			break;
		temp = temp->next;
	}
	if (temp->next == nullptr && temp->name != pozition)
		cout << "Такого элемента нет" << endl;
	else 
	{
		item->next = temp->next;
		item->name = Name;
		temp->next = item;
	}
	
	temp = nullptr;
}

void addToList_before(string Name, string pozition)
{
	MainList* item = new MainList();
	MainList* temp = List;
	while (temp->next->name != pozition)
	{
		if (temp->next->next == nullptr)
			break;
		temp = temp->next;
	}
	if (temp->next->next == nullptr && temp->next->name != pozition)
		cout << "Такого элемента нет" << endl;
	else
	{
		item->name = Name;
		item->next = temp->next;
		temp->next = item;
	}
	temp = nullptr;
}

MainList* Find_List(string Name);

void pop(string name, int value)
{
	if (Find_List(name) != nullptr)
	{
		if (!isEmpty(Find_List(name)->next))
		{
			MainList* Temp = Find_List(name)->next;
			MyList* temp = Temp->list;
			if (Temp->list->data == value)
			{
				Temp->list = Temp->list->next;
				Temp = nullptr;
				delete temp;
			}
			else if (temp->next != nullptr)
			{
				while (temp->next->data != value)
				{
					if (temp->next->next == nullptr)
						break;
					temp = temp->next;
				}
				if (temp->next->data != value && temp->next->next == nullptr)
				{
					cout << "Элемента с таким значенем нет.\n";
					temp = nullptr;
				}
				else
				{
					MyList* temp1 = temp->next;
					temp->next = temp->next->next;
					temp = nullptr;
					delete temp;
				}
			}
			else
			{
				cout << "Элемента с таким значенем нет.\n";
				temp = nullptr;
			}
		}
		else
			cout << "Список пуст\n\n";
		
	}
	else
	{
		cout << "Такого списка нет\n\n";
	}
}

void popFromList(string Name)
{
	if (!isMainEmpty())
	{
		MainList* temp = List, *temp1;
		while (temp->next->name != Name)
		{
			if (temp->next->next == nullptr)
				break;
			temp = temp->next;
		}
		if (temp->next->next == nullptr && temp->next->name != Name)
			cout << "Такого списка нет\n\n";
		else
		{
			temp1 = temp->next;
			temp->next = temp->next->next;
			temp = nullptr;
			MyList* Temp = temp1->list, *Temp1;
			while (Temp != nullptr)
			{
				Temp1 = Temp;
				Temp = Temp->next;
				delete Temp1;
			}
			delete temp1;
		}
		
	}
}

MainList* Find_List(string Name)
{
	if (!isMainEmpty())
	{
		MainList* temp = List;
		while (temp->next->name != Name)
		{
			if (temp->next->next == nullptr)
				return nullptr;
			temp = temp->next;
		}
		return temp;
	}
	else
		return nullptr;
}

MyList* Find(int value)
{
	MainList* Temp = List->next;
	while (Temp != nullptr)
	{
		if (!isEmpty(Temp))
		{
			MyList* temp = Temp->list;
			while (temp != nullptr)
			{
				if (temp->data == value)
					return temp;
				temp = temp->next;
			}
			temp = nullptr;
		}
		Temp = Temp->next;
	}
	Temp = nullptr;
	return nullptr;
}

void add_after(string name, int value, int pozition = 0)
{
	if (Find_List(name) != nullptr)
	{
		MainList* Temp = Find_List(name)->next;
		MyList* item = new MyList();
		if (isEmpty(Temp))
		{
			item->data = value;
			item->next = nullptr;
			Temp->list = item;
		}
		else
		{
			MyList* temp = Temp->list;
			while (temp->data != pozition)
			{
				if (temp->next == nullptr)
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
		Temp = nullptr;
	}
	else cout << "Такого списка нет\n";
}

void add_before(string name, int value, int pozition)
{
	if (Find_List(name) != nullptr)
	{
		MainList* Temp = Find_List(name)->next;
		MyList* item = new MyList();
		if (Temp->list->data == pozition)
		{
			item->data = value;
			item->next = Temp->list;
			Temp->list = item;
		}
		else if (Temp->list->next == nullptr)
			cout << "Такого элемента нет\n";
		else
		{
			MyList* temp = Temp->list;
			while (temp->next->data != pozition)
			{
				if (temp->next->next == nullptr)
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
		Temp = nullptr;
	}
	else cout << "Такого списка нет\n";
}

void print()
{
	if (isMainEmpty())
		cout << "Список пуст.\n\n";
	else
	{
		MainList* Temp = List->next;
		while (Temp != nullptr)
		{
			cout << Temp->name << ": " << endl;
			if (isEmpty(Temp))
				cout << "Список пуст.\n\n";
			else
			{
				MyList* temp = Temp->list;
				while (temp != nullptr)
				{
					cout << temp->data << endl;
					temp = temp->next;
				}
				cout << endl;
				temp = nullptr;
			}
			Temp = Temp->next;
		}
		cout << endl;
		Temp = nullptr;
	}
}

void clean()
{
	MainList* Temp = List, *Del;
	while (Temp != nullptr)
	{
		MyList* temp = Temp->list, *del;
		while (temp != nullptr)
		{
			del = temp;
			temp = temp->next;
			delete del;
		}
		Del = Temp;
		Temp = Temp->next;
		delete Del;
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
	int number, value, poz;
	bool flag = true;
	string name, Poz;
	while (flag)
	{
		cout << "1. Вывести состояние списка\n";
		cout << "2. Добавить элемент\n";
		cout << "3. Удалить элемент\n";
		cout << "0. Завершить работу программы\n";
		cout << "Введите номер команды:\n";
		number = entering();
		cout << endl;
		switch (number)
		{
		case 1:
			print();
			break;
		case 2:
			if (isMainEmpty())
			{
				cout << "Ведите имя добавляемого списка\n";
				cin >> name;
				addToList_after(name);
				cout << endl;
			}
			else
			{
				cout << "1. Добавить в главный список\n";
				cout << "2. Добавить в подсписок\n";
				number = entering();
				cout << endl;
				switch (number)
				{
				case 1:
					cout << "1. Добавить после заданного\n";
					cout << "2. Добавить до заданного\n";
					number = entering();
					cout << endl;
					switch (number)
					{
					case 1:
						cout << "Задайте имя списка, после которого нужно добавить элемент\n";
						cin >> Poz;
						cout << "Введите имя нового элемента-списка\n";
						cin >> name;
						addToList_after(name, Poz);
						cout << endl;
						break;
					case 2:
						cout << "Задайте имя списка, до которого нужно добавить элемент\n";
						cin >> Poz;
						cout << "Введите имя нового элемента-списка\n";
						cin >> name;
						addToList_before(name, Poz);
						cout << endl;
						break;
					default:
						cout << "Такой команды нет.\n";
						cout << endl;
						break;
					}
					break;
				case 2:
					cout << "Введите имя списка, в который нужно добавить элемент\n";
					cin >> name;
					cout << endl;
					if (Find_List(name) == nullptr)
						cout << "Такого списка нет\n\n";
					else
					{
						if (isEmpty(Find_List(name)->next))
						{
							cout << "Введите значение\n";
							value = entering();
							add_after(name, value);
							cout << endl;
						}
						else
						{
							cout << "1. Добавить после заданного\n";
							cout << "2. Добавить до заданного\n";
							number = entering();
							cout << endl;
							switch (number)
							{
							case 1:
								cout << "Задайте элемент из списка" << name << endl;
								poz = entering();
								cout << "Введите значение\n";
								value = entering();
								add_after(name, value, poz);
								cout << endl;
								break;
							case 2:
								cout << "Задайте элемент из списка" << name << endl;
								poz = entering();
								cout << "Введите значение\n";
								value = entering();
								add_before(name, value, poz);
								cout << endl;
								break;
							default:
								cout << "Такой команды нет.\n\n";
								break;
							}
						}
					}
					break;
				default:
					cout << "Такой команды нет.\n\n";
					break;
				}
			}
			
			break;

		case 3:
			cout << "1.Удалить элемент из главного списка\n";
			cout << "2.Удалить элемент из подсписка\n";
			number = entering();
			cout << endl;
			switch (number)
			{
			case 1:
				if (!isMainEmpty())
				{
					cout << "Введите имя списка, которой нужно удалить\n";
					cin >> name;
					popFromList(name);
					cout << endl;
				}
				else cout << "Список пуст\n\n";
				break;
			case 2:
				cout << "Введите имя списка, из которого нужно удалить элемент\n";
				cin >> name;
				cout << endl;
				if (Find_List(name) != nullptr)
				{
					cout << "Введите значение удаляемого элемента\n";
					value = entering();
					pop(name, value);
					cout << endl;
				}
				else
					cout << "Такого списка нет\n\n";
				break;
			default:
				cout << "Такой команды нет.\n\n";
				break;
			}
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "Такой команды нет. Повторите ввод команды\n\n";
		}
	}
}

int main()
{
	setlocale(0, "");
	initialization();
	menu();
	clean();
}