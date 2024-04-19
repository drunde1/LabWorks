#include <iostream>
#include <string>
using namespace std;


int calculate(string key, int M)
{
    int code = 0;
    for (int i = 0; i < key.length(); i++)
        code += (int)key[i];
    return code % M;
}


void print(string* table, int M)
{
    cout << "��� �������:" << endl;
    for (int i = 0; i < M; i++)
        cout << "�������� ������ - " << i << "; ����� - " << table[i] << endl;
    cout << endl;
}

bool isSame(string* table, string key, int M, int& compareAmount)
{
    for (int i = 0; i < M; i++)
    {
        compareAmount++;
        if (table[i] == key)
            return true;
    }
    return false;
}

int Add(string* table, string key, int M)
{
    int compareAmount = 0;
    if (isSame(table, key, M, compareAmount))
    {
        cout << "������ ������ � ������� ������ �����\n";
        compareAmount = -compareAmount;
    }
    else
    {
        int codeInd = calculate(key, M);
        compareAmount++;
        if (table[codeInd] != "")
        {
            int i = 1;
            int j = codeInd;
            while (i < M && table[j] != "")
            {
                j = ((codeInd + i) % M);
                i++;
                compareAmount++;
            }
            table[j] = key;
        }
        else
            table[codeInd] = key;
    }
    return compareAmount;
}

int Find(string* table, string key, int M)
{
    int pos = -1;
    int compareAmount = 0;
    int index = calculate(key, M);
    compareAmount++;
    if (table[index] == key)
        pos = index;
    else
    {
        int i = 1;
        int j = index;
        while (i < M && table[j] != key)
        {
            j = (index + i) % M;
            i++;
            compareAmount++;
        }
        if (table[j] == key)
            pos = j;
    }

    if (pos == -1)
        cout << "����� ��� � �������" << endl;
    else
        cout << "���� ������ ��� �������� " << pos << endl;
    return compareAmount;
}

void For11_13_17()
{
    string keys[10] = { "Shchukin", "Boyarkin", "Miftahutdinov", "Ogorodnikov", "Vasiliev", "Hasanshin", "Fardiev", "Ivanov", "Smirnov", "Sobolev" };

    cout << "������ � �������� ����������� 11\n" << endl;
    string table1[11];
    int comparesAdd_11 = 0;
    int comparesFind_11 = 0;
    for (int i = 0; i < 10; i++)
        comparesAdd_11 += Add(table1, keys[i], 11);
    cout << "1 �������: " << endl;
    print(table1, 11);

    for (int i = 0; i < 10; i++)
        comparesFind_11 += Find(table1, keys[i], 11);

    cout << "���������� ��������� ��� ���������� ��������� = " << comparesAdd_11 << endl;
    cout << "���������� ��������� ��� ������ ��������� = " << comparesFind_11 << endl << endl;

    cout << "������ � �������� ����������� 13\n" << endl;
    string table2[13];
    int comparesAdd_13 = 0;
    int comparesFind_13 = 0;
    for (int i = 0; i < 10; i++)
        comparesAdd_13 += Add(table2, keys[i], 13);
    cout << "2 �������: " << endl;
    print(table2, 13);

    for (int i = 0; i < 10; i++)
        comparesFind_13 += Find(table2, keys[i], 13);

    cout << "���������� ��������� ��� ���������� ��������� = " << comparesAdd_13 << endl;
    cout << "���������� ��������� ��� ������ ��������� = " << comparesFind_13 << endl << endl;

    cout << "������ � �������� ����������� 17\n" << endl;
    string table3[17];
    int comparesAdd_17 = 0;
    int comparesFind_17 = 0;
    for (int i = 0; i < 10; i++)
        comparesAdd_17 += Add(table3, keys[i], 17);
    cout << "3 �������: " << endl;
    print(table3, 17);

    for (int i = 0; i < 10; i++)
        comparesFind_17 += Find(table3, keys[i], 17);

    cout << "���������� ��������� ��� ���������� ��������� = " << comparesAdd_17 << endl;
    cout << "���������� ��������� ��� ������ ��������� = " << comparesFind_17 << endl << endl;

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
    setlocale(LC_ALL, "russian");
    int M;
    cout << "������� ������ ���-�������" << endl;
    M = failure();
    cout << endl;
    string* table = new string[M];
    int com;
    string key;
    int inputCount = 0;
    while (true)
    {
        cout << "�������� ��������:\n";
        cout << "1. ������ ���� � ���-�������\n";
        cout << "2. ����� ���� � ���-�������\n";
        cout << "3. ������� �������\n";
        cout << "4. ������ ��������� ��� ������ ������� 11, 13, 17\n";
        cout << "0. ��������� ������ � ��������\n";
        cout << "��� �����: ";
        com = failure();
        cout << endl;
        if (com == 1)
        {
            if (inputCount < M)
            {
                cout << "������� ����, ������� �� ������ ������" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                getline(cin, key);
                int compareAmount = Add(table, key, M);
                if (compareAmount > 0)
                    inputCount++;
                cout << "���������� ��������� ��� ���������� �������� = " << compareAmount << endl;
            }
            else
                cout << "������� �����\n";
        }
        else if (com == 2)
        {
            cout << "������� ����, ������� �� ������ �����" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            getline(cin, key);
            int compareAmount = Find(table, key, M);
            cout << "���������� ��������� ��� ������ �������� = " << compareAmount << endl;
        }
        else if (com == 3)
            print(table, M);
        else if (com == 4)
            For11_13_17();
        else if (com == 0)
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
