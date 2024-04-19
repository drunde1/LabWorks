#include <iostream>
#include <cstdlib>

using namespace std;

bool find_succsess = false, l = false, r = false;

struct Tree
{
	Tree* left = nullptr;
	Tree* right = nullptr;
	int value = 0;
	int counter = 0;
}*tree = nullptr, *element = nullptr, *parent = nullptr;

bool isEmpty()
{
	if (tree == nullptr)
		return 1;
	else return 0;
}

void find(Tree* pointer, int value)
{
	if (!find_succsess)
	{
		if (pointer != nullptr)
		{
			if (pointer->value == value)
			{
				element = pointer;
				find_succsess = true;
			}
			else
			{
				find(pointer->left, value);
				find(pointer->right, value);
			}
		}
	}
}

void find_parent(Tree* pointer, Tree* el)
{
	if (!find_succsess)
	{
		if (pointer != nullptr)
		{
			if (pointer->left == el)
			{
				parent = pointer;
				find_succsess = true;
				l = true;
			}
			else if (pointer->right == el)
			{
				parent = pointer;
				find_succsess = true;
				r = true;
			}
			else
			{
				find_parent(pointer->left, el);
				find_parent(pointer->right, el);
			}
		}
	}
}

inline void add(Tree* &pointer, int value)
{
	pointer = new Tree();
	pointer->left = nullptr;
	pointer->right = nullptr;
	pointer->value = value;
	pointer->counter++;
}

void add_recursion(Tree* &pointer, int value)
{
	if (pointer == nullptr)
		add(pointer, value);
	else
	{
		if (value == pointer->value)
			pointer->counter++;
		else if (value > pointer->value)
			add_recursion(pointer->right, value);
		else if (value < pointer->value)
			add_recursion(pointer->left, value);
	}
}

void add_unrecursion(int value)
{
	if (!isEmpty())
	{
		Tree* temp = tree;
		Tree* partemp = temp;
		while (temp != nullptr)
		{
			if (value > temp->value)
			{
				partemp = temp;
				temp = temp->right;
			}
			else if (value < temp->value)
			{
				partemp = temp;
				temp = temp->left;
			}
			else if (value == temp->value)
			{
				temp->counter++;
				break;
			}
		}
		if (temp == partemp->left)
			add(partemp->left, value);
		else if (temp == partemp->right)
			add(partemp->right, value);
	}
	else
		add(tree, value);
}

void print_backsymm(Tree* pointer, int level)
{	
	if (isEmpty())
		cout << "Дерево пусто\n\n";
	if (pointer != nullptr)
	{
		print_backsymm(pointer->right, level + 1);
		string str;
		//int deleted;
		for (int i = 0; i < level; i++)
			str += "     ";


		/*if (pointer->counter > 1)
			deleted = pointer->value;
		else if (pointer->left == nullptr && pointer->right == nullptr)
			deleted = -1;
		else if (pointer->left == nullptr && pointer->right != nullptr)
			deleted = pointer->right->value;
		else if (pointer->left != nullptr && pointer->right == nullptr)
			deleted = pointer->left->value;
		else if (pointer->left != nullptr && pointer->right != nullptr)
		{
			Tree* temp = pointer->right;
			while (temp->left != nullptr)
				temp = temp->left;
			deleted = temp->value;
		}*/


		cout << str << pointer->value << endl;
		print_backsymm(pointer->left, level + 1);
	}
	
}

Tree* clear(Tree* pointer)
{
	if (pointer != nullptr)
	{
		clear(pointer->left);
		clear(pointer->right);
		cout << "Вершина " << pointer->value << " удалена\n";
		delete pointer;
	}
	return nullptr;
}

void print_line(Tree* pointer)
{
	if (isEmpty())
		cout << "Дерево пусто\n\n";
	if (pointer != nullptr)
	{
		print_line(pointer->left);
		cout << pointer->value << "(" << pointer->counter << ")  ";
		print_line(pointer->right);
	}
}

void pop(Tree* pointer, int value)
{
	if (!isEmpty())
	{
		find_succsess = false;
		element = nullptr;
		find(tree, value);
		if (element == nullptr)
			cout << "Такой вершины нет\n\n";
		else if (element == tree)
		{
			if (tree->counter > 1)
				tree->counter--;
			else if (tree->left == nullptr && tree->right == nullptr)
			{
				tree = nullptr;
				delete element;
			}
			else if (element->left == nullptr && element->right != nullptr)
			{
				tree = tree->right;
				delete element;
			}
			else if (element->left != nullptr && element->right == nullptr)
			{
				tree = tree->left;
				delete element;
			}
			else if (element->left != nullptr && element->right != nullptr)
			{
				Tree* temp = element->right;
				while (temp->left != nullptr)
					temp = temp->left;
				find_succsess = false;
				find_parent(tree, temp);
				temp->left = tree->left;
				if (temp != element->right)
				{
					parent->left = temp->right;
					temp->right = tree->right;
				}
				tree = temp;
				delete element;
			}
			element = nullptr;
			parent = nullptr;
		}
		else
		{
			find_succsess = false;
			parent = nullptr;
			l = false;
			r = false;
			find_parent(tree, element);
			if (element->counter > 1)
				element->counter--;
			else if (element->left == nullptr && element->right == nullptr)
			{
				if (r)
					parent->right = nullptr;
				else if (l)
					parent->left = nullptr;
				delete element;
			}
			else if (element->left == nullptr && element->right != nullptr)
			{
				if (r)
					parent->right = element->right;
				else if (l)
					parent->left = element->right;
				delete element;
			}
			else if (element->left != nullptr && element->right == nullptr)
			{
				if (r)
					parent->right = element->left;
				else if (l)
					parent->left = element->left;
				delete element;
			}
			else if (element->left != nullptr && element->right != nullptr)
			{
				Tree* temp = element->right;
				while (temp->left != nullptr)
					temp = temp->left;
				Tree* par = parent;
				bool l1 = l;
				bool r1 = r;
				l = false;
				r = false;
				find_succsess = false;
				find_parent(tree, temp);
				temp->left = element->left;
				if (temp != element->right)
				{
					parent->left = temp->right;
					temp->right = element->right;
				}
				if (r1)
					par->right = temp;
				else if (l1)
					par->left = temp;
				par = nullptr;
				delete element;
			}
			parent = nullptr;
			element = nullptr;
		}
	}
	else
		cout << "Дерево пусто\n\n";
	
}

void Random(int number)
{
	for (int i = 0; i < number; i++)
		add_recursion(tree, rand() % 100);
}

int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОшибка ввода. Повторите ввод.\n" << endl;
	}
	return a;
}

int main()
{
	setlocale(0, "");
	int comand;
	cout << "Введите количество ключей:\n";
	comand = failure();
	Random(comand);
	while (true)
	{
		cout << "\n1. Добавить элемент\n";
		cout << "2. Вывод в наглядном виде\n";
		cout << "3. Вывод в порядке возрастания ключей\n";
		cout << "4. Поиск элемента\n";
		cout << "5. Удалить элемент\n";
		cout << "0. Завершить работу программы\n";
		comand = failure();
		cout << endl;
		if (comand == 1)
		{
			cout << "1. Добавить рекурсивно\n";
			cout << "2. Добавить не рекурсивно\n";
			comand = failure();
			cout << endl;
			if (comand == 1)
			{
				cout << "Введите значени:\n";
				comand = failure();
				add_recursion(tree, comand);
			}
			else if (comand == 2)
			{
				cout << "Введите значени:\n";
				comand = failure();
				add_unrecursion(comand);
			}
			else
				cout << "Такой команды нет\n\n";
		}
		else if (comand == 2)
			print_backsymm(tree, 0);
		else if (comand == 3)
		{
			print_line(tree);
			cout << endl;
		}
		else if (comand == 4)
		{
			cout << "Введите значени:\n";
			comand = failure();
			find(tree, comand);
			if (element == nullptr)
				cout << "Такого элемента нет\n\n";
			else
				cout << "Этот элемент встречается " << element->counter << " раз(а)\n\n";
			element = nullptr;
			find_succsess = false;
		}
		else if (comand == 5)
		{
			cout << "Введите значени:\n";
			comand = failure();
			pop(tree, comand);
		}
		else if (comand == 0)
			break;
		else
			cout << "Такой команды нет\n\n";
	}
	clear(tree);
	
	return 0;
}