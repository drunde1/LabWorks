#include <iostream>
#include <cstdlib>

using namespace std;

int N;

struct Tree
{
    Tree* right;
    Tree* left;
    int value;
}*tree = nullptr;

Tree* build(Tree* pointer, int Num)
{
    Tree* temp;
    int Nl, Nr;
    if (Num == 0)
        return nullptr;
    else
    {
        Nl = Num / 2;
        Nr = Num - Nl - 1;
        temp = new Tree();
        temp->value = rand() % 100;
        temp->left = build(temp->left, Nl);
        temp->right = build(temp->right, Nr);
        return temp;
    }
}

void print_forward(Tree* pointer, int level)
{
    if (pointer != nullptr)
    {
        string str;
        for (int i = 0; i < level; i++)
            str += "     ";
        cout << str << pointer->value << endl;
        print_forward(pointer->left, level + 1);
        print_forward(pointer->right, level + 1);
    }
}

void print_symm(Tree* pointer, int level)
{
    if (pointer != nullptr)
    {
        print_symm(pointer->left, level + 1);
        string str;
        for (int i = 0; i < level; i++)
            str += "     ";
        cout << str << pointer->value << endl;
        print_symm(pointer->right, level + 1);
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

void clear(Tree* pointer)
{
    if (pointer != nullptr)
    {
        clear(pointer->left);
        clear(pointer->right);
        delete pointer;
    }
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

void menu()
{
    int number;
    while (true)
    {
        cout << "1. Сформиовать новое дерево\n";
        cout << "2. Вывод в прямом порядке\n";
        cout << "3. Вывод в симметрином порядке\n";
        cout << "4. Вывод в обратносимметричном порядке\n";
        cout << "0. Завершить работу программы\n";
        number = failure();

        if (number == 1)
        {
            if (tree != nullptr)
            {
                clear(tree);
                tree = nullptr;
            }
            cout << "Введите число вершин:\n";
            N = failure();
            tree = build(tree, N);
        }
        else if (number == 2)
        {
            if (tree != nullptr)
                print_forward(tree, 0);
            else
                cout << "Дерево пусто\n\n";
        }
        else if (number == 3)
        {
            if (tree != nullptr)
                print_symm(tree, 0);
            else
                cout << "Дерево пусто\n\n";
        }
        else if (number == 4)
        {
            if (tree != nullptr)
                print_backsymm(tree, 0);
            else
                cout << "Дерево пусто\n\n";
        }
        else if (number == 0)
            break;
        else
            cout << "Такой команды нет\n\n";
    }
}

int main()
{
    setlocale(0, "");
    menu();
    clear(tree);

    return 0;
}