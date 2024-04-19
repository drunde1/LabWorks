#include <iostream>

using namespace std;

bool find_succsess = false;

struct Tree
{
	Tree* left;
	Tree* right;
	int value;
}*tree = nullptr, *parent = nullptr;

bool isEmpty()
{
	if (tree == nullptr)
		return 1;
	else return 0;
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

void find(Tree* pointer, int value)
{
	if (!find_succsess)
	{
		if (pointer != nullptr)
		{
			if (pointer->value == value)
			{
				parent = pointer;
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

inline void addleft()
{
	parent->left = new Tree();
	parent->left->left = nullptr;
	parent->left->right = nullptr;
	cout << "Введите значение добавляемого элемента:\n";
	int value = failure();
	parent->left->value = value;
	cout << endl;
}

inline void addright()
{
	parent->right = new Tree();
	parent->right->left = nullptr;
	parent->right->right = nullptr;
	cout << "Введите значение добавляемого элемента:\n";
	int value = failure();
	parent->right->value = value;
	cout << endl;
}

void add()
{
	if (isEmpty())
	{
		cout << "Дерево пусто\n";
		tree = new Tree();
		tree->left = nullptr;
		tree->right = nullptr;
		cout << "Введите значение корня:\n";
		tree->value = failure();
		cout << endl;
	}
	else
	{
		cout << "Введите искомое значение информационной части родителя:\n";
		int Parent = failure();
		cout << endl;
		find_succsess = false;
		parent = nullptr;
		find(tree, Parent);
		if (parent != nullptr)
		{
			if (parent->left != nullptr && parent->right != nullptr)
				cout << "Добавление невозможно\n\n";
			else if (parent->left != nullptr && parent->right == nullptr)
			{
				cout << "Добавление возможно только в правую ветвь\n";
				addright();
			}
			else if (parent->left == nullptr && parent->right != nullptr)
			{
				cout << "Добавление возможно только в левую ветвь\n";
				addleft();
			}
			else if (parent->left == nullptr && parent->right == nullptr)
			{
				int choice;
				while (true)
				{
					cout << "В какую ветвь добавить:\n 1. Левую\n 2. Правую\n";
					choice = failure();
					cout << endl;
					if (choice == 1)
					{
						addleft();
						break;
					}
					else if (choice == 2)
					{
						addright();
						break;
					}
					else
						"Такой команды нет\n\n";
				}
			}
		}
		else
		{
			cout << "Такого элемента нет\n\n";
		}
		
	}
}

void print_backsymm(Tree* pointer, int level)
{
	if (pointer != nullptr)
	{
		print_backsymm(pointer->right, level + 1);
		string str;
		for (int i = 0; i < level; i++)
			str += "     ";
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

int main()
{
	setlocale(0, "");
	int comand;
	while (true)
	{
		cout << "\n1. Добавить элемент\n";
		cout << "2. Вывод в обратно-симметричном порядке\n";
		cout << "3. Очистить дерево\n";
		cout << "0. Завершить работу программы\n";
		comand = failure();
		cout << endl;
		if (comand == 1)
			add();
		else if (comand == 2)
			print_backsymm(tree, 0);
		else if (comand == 3)
			tree = clear(tree);
		else if (comand == 0)
			break;
		else
			cout << "Такой команды нет\n\n";
	}
	clear(tree);
	return 0;
}