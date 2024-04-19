#include <iostream>
#include <algorithm>

using namespace std;

int* arr = nullptr;
int length = 0;

struct list
{
    int key = -1;
    list* next = nullptr;
};
struct Arr
{
    int key = -1;
    list* first = nullptr;
    list* end = nullptr;
};

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

void print(int* pointer)
{
    for (int i = 0; i < length; i++)
        cout << pointer[i] << "  ";
    cout << endl;
}

void creation(bool forbucket, int keysamount)
{
    if (arr == nullptr)
    {
        while (true)
        {
            cout << "Введите длину массива не более 10000\n";
            length = failure();
            if (length <= 10000 && length >= 1)
                break;
            else
                cout << "Длина должна быть в пределах от 1 до 10000\n";
        }
        arr = new int[length];
        if (forbucket)
        {
            for (int i = 0; i < length; i++)
                arr[i] = i;
            random_shuffle(&arr[0], &arr[length]);
        }
        else if (keysamount > 0)
        {
            for (int i = 0; i < length; i++)
                arr[i] = rand() % keysamount;
        }
        else
        {
            for (int i = 0; i < length; i++)
                arr[i] = rand() % length;
        }
        cout << endl << "До сортировки:\n";
        print(arr);
    }
    else
    {
        delete[] arr;
        arr = nullptr;
        creation(forbucket,keysamount);
    }
}

void BucketSortWithoutArray()
{
    creation(1, 0);
    int temp;
    for (int i = 0; i < length; i++)
    {
        while (arr[i] != i)
        {
            temp = arr[arr[i]];
            arr[arr[i]] = arr[i];
            arr[i] = temp;
        }
    }
    cout << endl << "После сортировки:\n";
    print(arr);
    delete[] arr;
    arr = nullptr;
}

void BucketSortWithArray()
{
    creation(1, 0);
    int* secarr = new int[length];
    for (int i = 0; i < length; i++)
        secarr[arr[i]] = arr[i];
    for (int i = 0; i < length; i++)
        arr[i] = secarr[i];
    cout << endl << "После сортировки:\n";
    print(arr);
    delete[] arr;
    delete[] secarr;
    arr = nullptr;
}

void BucketSort()
{
    cout << "1. Без дополнительного массива\n";
    cout << "2. С дополнительным массивом\n";
    cout << "Введите команду:\n";
    int com = failure();
    cout << endl;
    if (com == 1)
        BucketSortWithoutArray();
    else if (com == 2)
        BucketSortWithArray();
    else
    {
        cout << "Такой команды нет\n";
        BucketSort();
    }
}

void GeneralBucketSort()
{
    cout << "Введите количество ключей\n";
    int keysAmount = failure();
    creation(0, keysAmount);
    Arr* arrOfLists = new Arr[keysAmount];

    for (int i = 0; i < length; i++)
    {

        if (arrOfLists[arr[i]].key == -1)
        {
            arrOfLists[arr[i]].key = arr[i];
            list* newlist = new list;
            newlist->key = arr[i];
            arrOfLists[arr[i]].first = newlist;
            arrOfLists[arr[i]].end = newlist;
        }
        else
        {
            list* newlist = new list;
            newlist->key = arr[i];
            arrOfLists[arr[i]].end->next = newlist;
            arrOfLists[arr[i]].end = newlist;
        }
    }
    list* listTopStart = arrOfLists[0].first;
    list* listTopLast = arrOfLists[0].end;

    for (int i = 0; i < keysAmount - 1; i++)
    {
        if (listTopLast == nullptr)
        {

            listTopStart = arrOfLists[i].first;
            listTopLast = arrOfLists[i].end;
            if (listTopLast != nullptr)
            {
                listTopLast->next = arrOfLists[i + 1].first;
                if (arrOfLists[i + 1].key != -1)
                    listTopLast = arrOfLists[i + 1].end;
            }
        }
        else
        {
            listTopLast->next = arrOfLists[i + 1].first;
            if (arrOfLists[i + 1].key != -1)
                listTopLast = arrOfLists[i + 1].end;
        }
    }
    list* temp = listTopStart;
    for (int i = 0; i < length; i++)
    {
        arr[i] = temp->key;
        temp = temp->next;
    }

    cout << endl << "После сортировки\n";
    print(arr);

    list* tempD;
    while (listTopStart != nullptr)
    {
        tempD = listTopStart;
        listTopStart = listTopStart->next;
        delete tempD;
    }
    delete[] arrOfLists;
}

int getMax()
{
    int max = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void ForRadix(int place)
{
    Arr* arrOfLists = new Arr[10];
    for (int i = 0; i < 10; i++)
    {
        arrOfLists[i].key = i;
        arrOfLists[i].first = nullptr;
        arrOfLists[i].end = nullptr;
    }

    for (int i = 0; i < length; i++)
    {

        if (arrOfLists[(arr[i] / place) % 10].first == nullptr)
        {
            list* newlist = new list;
            newlist->key = arr[i];
            arrOfLists[(arr[i] / place) % 10].first = newlist;
            arrOfLists[(arr[i] / place) % 10].end = newlist;
        }
        else
        {
            list* newlist = new list;
            newlist->key = arr[i];
            arrOfLists[(arr[i] / place) % 10].end->next = newlist;
            arrOfLists[(arr[i] / place) % 10].end = newlist;
        }
    }
    list* listTopStart = arrOfLists[0].first;
    list* listTopLast = arrOfLists[0].end;

    for (int i = 0; i < 9; i++)
    {
        if (listTopLast == nullptr)
        {

            listTopStart = arrOfLists[i].first;
            listTopLast = arrOfLists[i].end;
            if (listTopLast != nullptr)
            {
                listTopLast->next = arrOfLists[i + 1].first;
                if (arrOfLists[i + 1].first != nullptr)
                    listTopLast = arrOfLists[i + 1].end;
            }
        }
        else
        {
            listTopLast->next = arrOfLists[i + 1].first;
            if (arrOfLists[i + 1].first != nullptr)
                listTopLast = arrOfLists[i + 1].end;
        }
    }
    list* temp = listTopStart;
    for (int i = 0; i < length; i++)
    {
        arr[i] = temp->key;
        temp = temp->next;
    }

    list* tempD;
    while (listTopStart != nullptr)
    {
        tempD = listTopStart;
        listTopStart = listTopStart->next;
        delete tempD;
    }
    delete[] arrOfLists;
}

void RadixSort()
{
    creation(0, 0);
    int maxElem = getMax();
    for (int place = 1; maxElem / place > 0; place *= 10)
        ForRadix(place);
    cout << endl << "После сортировки\n";
    print(arr);
}

int main()
{
    setlocale(0, "");
    int comand;
    while (true)
    {
        cout << "1. Карманная сортировка\n";
        cout << "2. Обобщенная карманная сортировка\n";
        cout << "3. Поразрядна сортировка\n";
        cout << "0. Завершить работу программы\n";
        comand = failure();
        cout << endl;
        if (comand == 1)
            BucketSort();
        else if (comand == 2)
            GeneralBucketSort();
        else if (comand == 3)
            RadixSort();
        else if (comand == 0)
            break;
        else cout << "Такой команды нет\n\n";
    }

    delete[] arr;

    return 0;
}