#include <iostream>
#include <cstdlib>

using namespace std;

int* arr = nullptr;
int comparisons = 0, exchanges = 0, length = 0;

int failure()
{
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

void creation()
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
        for (int i = 0; i < length; i++)
            arr[i] = rand() % length;
        print(arr);
	}
    else
    {
        delete[] arr;
        arr = nullptr;
        creation();
    }
}

int* copy()
{
    int* secarr = new int[length];
    for (int i = 0; i < length; i++)
        secarr[i] = arr[i];
    return secarr;
}

void Bubble_sort()
{
    int* secarr = copy();
    int temp = 0;
    for (int i = 0; i < length; i++) 
    {
        for (int j = (length - 1); j >= (i + 1); j--)   
        {
            comparisons++;
            if (secarr[j] < secarr[j - 1]) 
            {
                temp = secarr[j];
                secarr[j] = secarr[j - 1];
                secarr[j - 1] = temp;
                exchanges += 3;
            }
        }
    }
    print(secarr);
    cout << "Количество сравнений: " << comparisons << endl;
    cout << "Количество пересылок: " << exchanges << endl;
    delete[] secarr;
    comparisons = 0;
    exchanges = 0;
}

void Selection_sort()
{
    int* secarr = copy();
    int j = 0;
    int temp = 0;
    for (int i = 0; i < length - 1; i++)
    {
        j = i;
        for (int k = i + 1; k < length; k++)
        {
            comparisons++;
            if (secarr[j] > secarr[k])
            {
                j = k;
            }
        }
        if (j != i)
        {
            temp = secarr[i];
            secarr[i] = secarr[j];
            secarr[j] = temp;
            exchanges += 3;
        }
    }
    print(secarr);
    cout << "Количество сравнений: " << comparisons << endl;
    cout << "Количество пересылок: " << exchanges << endl;
    delete[] secarr;
    comparisons = 0;
    exchanges = 0;
}

void Insertion_sort()
{
    int* secarr = copy();
    int key = 0;
    int i = 0;
    for (int j = 1; j < length; j++) 
    {
        key = secarr[j];
        exchanges++;
        i = j - 1;
        while (i >= 0 && secarr[i] > key)
        {
            i--;
            comparisons++;
        }
        if (!(i == j - 1))
        {
            for (int v = j; v > i + 1; v--)
            {
                secarr[v] = secarr[v - 1];
                exchanges++;
            }
            secarr[i + 1] = key;
            exchanges++;
        }
    }
    print(secarr);
    cout << "Количество сравнений: " << comparisons << endl;
    cout << "Количество пересылок: " << exchanges << endl;
    delete[] secarr;
    comparisons = 0;
    exchanges = 0;
}

int main()
{
    setlocale(0, "");
    int comand;
    creation();
    while (true)
    {
        cout << "1. Сортировка обменом\n";
        cout << "2. Сортировка выбором\n";
        cout << "3. Сортировка вставками\n";
        cout << "4. Создать новый массив\n";
        cout << "0. Завершить работу программы\n";
        comand = failure();
        cout << endl;
        if (comand == 1)
            Bubble_sort();
        else if (comand == 2)
            Selection_sort();
        else if (comand == 3)
            Insertion_sort();
        else if (comand == 4)
            creation();
        else if (comand == 0)
            break;
        else cout << "Такой команды нет\n\n";
    }

    delete[] arr;
	return 0;
}