#include <iostream>
#include <string>
using namespace std;

struct List
{
    string key = "";
    List* next = nullptr;
};

struct Table
{
    bool free = true;
    List* top = nullptr;
    List* end = nullptr;
};

int calculating(string key, int M)
{
    int code = 0;
    for (int i = 0; i < key.length(); i++)
    {
        code += (int)key[i];
    }
    return code % M;
}

void print(Table* table, int M)
{
    for (int i = 0; i < M; i++)
    {
        if (!table[i].free)
        {
            List* current = table[i].top;
            while (current != nullptr)
            {
                cout << "���� � �������� " << i << ": " << current->key << endl;
                current = current->next;
            }
        }
    }
}

bool Find(Table* table, string key, int M, int& compareAmount)
{
    int inputCodeInd = calculating(key, M);
    List* current = table[inputCodeInd].top;
    int index = 0;
    while (current != nullptr)
    {
        index++;
        compareAmount++;
        if (current->key == key)
            break;
        current = current->next;
    }

    if (current == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }

}

int add(Table* table, string key, int M)
{
    int compareAmount = 0;
    {
        int codeInd = calculating(key, M);
        compareAmount++;
        if (table[codeInd].free == true)
        {
            table[codeInd].free = false;
            List* temp = new List;
            temp->key = key;
            temp->next = nullptr;
            table[codeInd].top = temp;
            table[codeInd].end = temp;
        }
        else
        {
            if (Find(table, key, M, compareAmount))
            {
                return -compareAmount;
            }
            else
            {
                List* temp = new List;
                temp->key = key;
                temp->next = nullptr;
                table[codeInd].end->next = temp;
                table[codeInd].end = temp;
            }
        }
    }
    return compareAmount;
}

int Find(Table* table, string key, int M)
{
    int compareAmount = 0;
    int inputCodeInd = calculating(key, M);
    List* current = table[inputCodeInd].top;
    int index = 0;
    while (current != nullptr)
    {
        index++;
        compareAmount++;
        if (current->key == key)
            break;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "������ ����� ���\n";
    }
    else
    {
        cout << "���� "<< key << " ������ � �������� " << index << " ���������������� ������ " << inputCodeInd << "�� �������� �������\n";
    }
    return compareAmount;
}

void pop(Table* table, string key, int M)
{
    int codeInd = calculating(key, M);
    List* current = table[codeInd].top;
    if (table[codeInd].free == false)
    {
        if (current->key == key)
        {
            table[codeInd].top = current->next;
            delete current;
            if (table[codeInd].top == nullptr)
            {
                table[codeInd].free = true;
                table[codeInd].end = nullptr;
            }
        }
        else
        {
            List* prev = nullptr;
            while (current != nullptr)
            {
                prev = current;
                current = current->next;
                if (current != nullptr && current->key == key)
                {
                    prev->next = current->next;
                    delete current;
                    break;
                }
            }
        }
    }
}

void clear(Table* table, int M)
{
    for (int i = 0; i < M; i++)
    {
        if (table[i].free == false)
        {
            List* current = table[i].top;
            List* temp = nullptr;
            while (current != nullptr)
            {
                temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
}

void For_9_17_23()
{
    string keys[20] = { "Shchukin", "Boyarkin", "Miftahutdinov", "Ogorodnikov", "Vasiliev", "Hasanshin", "Fardiev", "Ivanov", "Smirnov", "Sobolev",
        "shchukin", "boyarkin", "miftahutdinov", "ogorodnikov", "vasiliev", "hasanshin", "fardiev", "ivanov", "smirnov", "sobolev" };

    cout << "������� ����������� 9\n" << endl;
    Table table1[9];
    int comparesAdd_9 = 0;
    int comparesFind_9 = 0;
    for (int i = 0; i < 20; i++)
        comparesAdd_9 += add(table1, keys[i], 9);
    print(table1, 9);
    cout << endl;

    for (int i = 0; i < 20; i++)
        comparesFind_9 += Find(table1, keys[i], 9);

    cout << "���������� ��������� ��� ����������: " << comparesAdd_9 << endl;
    cout << "���������� ��������� ��� ������: " << comparesFind_9 << endl << endl;

    clear(table1, 9);

    cout << "������� ����������� 17" << endl;
    Table table2[17];
    int comparesAdd_17 = 0;
    int comparesFind_17 = 0;
    for (int i = 0; i < 20; i++)
        comparesAdd_17 += add(table2, keys[i], 17);
    print(table2, 17);
    cout << endl;

    for (int i = 0; i < 20; i++)
        comparesFind_17 += Find(table2, keys[i], 17);

    cout << "���������� ��������� ��� ����������: " << comparesAdd_17 << endl;
    cout << "���������� ��������� ��� ������: " << comparesFind_17 << endl << endl;

    clear(table2, 17);

    cout << "������� ����������� 23" << endl;
    Table table3[23];
    int comparesAdd_23 = 0;
    int comparesFind_23 = 0;
    for (int i = 0; i < 20; i++)
        comparesAdd_23 += add(table3, keys[i], 23);
    print(table3, 23);
    cout << endl;

    for (int i = 0; i < 20; i++)
        comparesFind_23 += Find(table3, keys[i], 23);

    cout << "���������� ��������� ��� ����������: " << comparesAdd_23 << endl;
    cout << "���������� ��������� ��� ������: " << comparesFind_23 << endl << endl;

    clear(table3, 23);

}

int failure()
{
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
    setlocale(0, "");
    int M;
    cout << "������� ������ ���-�������:" << endl;
    M = failure();
    Table* table = new Table[M];
    int answer;
    string key;
    int inputCount = 0;
    while (true)
    {
        cout << "�������� ��������:\n";
        cout << "1. ������ ���� � ���-�������\n";
        cout << "2. ����� ���� � ���-�������\n";
        cout << "3. ������� ���� �� ���-�������\n";
        cout << "4. ������� �������\n";
        cout << "5. ������ � ���������� ���������� 9, 17, 23\n";
        cout << "0. ��������� ������ � ��������\n";
        cout << "��� �����:\n ";
        answer = failure();
        cout << endl;
        if (answer == 1)
        {
            int compareAmount = 0;
            cout << "������� ����:" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            getline(cin, key);

            compareAmount = add(table, key, M);
            cout << "���������� ��������� ��� ���������� " << compareAmount << endl << endl;

        }
        else if (answer == 2)
        {
            cout << "������� ����, ������� �� ������ �����" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            getline(cin, key);
            int compareAmount = Find(table, key, M);
            cout << "���������� ��������� ��� ������: " << compareAmount << endl << endl;
        }
        else if (answer == 3)
        {
            cout << "������� ����, ������� �� ������ �������" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            getline(cin, key);
            pop(table, key, M);
        }
        else if (answer == 4)
            print(table, M);
        else if (answer == 5)
            For_9_17_23();
        else if (answer == 0)
        {
            delete[] table;
            break;
        }
    }

}

int main()
{
    menu();
    return 0;
}
