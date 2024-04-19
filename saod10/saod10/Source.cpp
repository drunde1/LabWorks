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

struct Stack
{
    Stack* next;
    Tree* node;
    int level;
}*stack;

void init()
{
    stack = new Stack();
    stack->level = -1;
    stack->next = nullptr;
    stack->node = tree;
}

bool isEmpty()
{
    if (stack->level == -1)
        return 1;
    else return 0;
}

void add(Tree* pointer, int level)
{
    Stack* item = new Stack();
    item->node = pointer;
    item->level = level;
    item->next = stack;
    stack = item;
}

Tree* pop()
{
    Stack* temp = stack;
    Tree* top = stack->node;
    stack = stack->next;
    delete temp;
    return top;
}

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

void print(int level, Tree* temp)
{
    for (int i = 0; i < level; i++)
        cout << "     ";
    cout << temp->value << endl;
}

void print_symm_cycle()
{
    Tree* temp = tree;
    int lev = 0;
    while (true)
    {
        while (temp != nullptr)
        {
            add(temp, lev);
            temp = temp->left;
            lev++;
        }
        if (isEmpty())
            break;
        else 
        { 
            lev = stack->level;
            temp = stack->node;
            print(lev, temp);
            pop();
            temp = temp->right;
            lev++;
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
        cout << "\n������ �����. ��������� ����.\n" << endl;
    }
    return a;
}

void menu()
{
    int number;
    while (true)
    {
        cout << "1. ����������� ����� ������\n";
        cout << "2. ����� � ������ �������\n";
        cout << "3. ����� � ����������� �������\n";
        cout << "4. ����� � ������������������� �������\n";
        cout << "5. ����� � ������������ ������� ��� ��������\n";
        cout << "0. ��������� ������ ���������\n";
        number = failure();

        if (number == 1)
        {
            if (tree != nullptr)
            {
                clear(tree);
                tree = nullptr;
            }
            cout << "������� ����� ������:\n";
            N = failure();
            tree = build(tree, N);
        }
        else if (number == 2)
        {
            if (tree != nullptr)
                print_forward(tree, 0);
            else
                cout << "������ �����\n\n";
        }
        else if (number == 3)
        {
            if (tree != nullptr)
                print_symm(tree, 0);
            else
                cout << "������ �����\n\n";
        }
        else if (number == 4)
        {
            if (tree != nullptr)
                print_backsymm(tree, 0);
            else
                cout << "������ �����\n\n";
        }
        else if (number == 5)
        {
            if (tree != nullptr)
                print_symm_cycle();
            else
                cout << "������ �����\n\n";
        }
        else if (number == 0)
            break;
        else
            cout << "����� ������� ���\n\n";
    }
}

int main()
{
    setlocale(0, "");
    init();
    menu();
    clear(tree);

    return 0;
}