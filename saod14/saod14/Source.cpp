#include <iostream>

using namespace std;

int* arr = nullptr;
int comparisons = 0, exchanges = 0, length = 0;

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

//усовершенствованная сортировка вставками
void Shell_sort()
{
    int* secarr = copy();
    int temp;
    for (int step = length / 2; step > 0; step /= 2)
    {
        int key = 0;
        int i = 0;
        for (int j = step; j < length; j++)
        {
            key = secarr[j];
            exchanges++;
            i = j - step;
            while (i >= 0 && secarr[i] > key)
            {
                i -= step;
                comparisons++;
            }
            if (!(i == j - step))
            {
                for (int v = j; v > i + step; v -= step)
                {
                    secarr[v] = secarr[v - step];
                    exchanges++;
                }
                secarr[i + step] = key;
                exchanges++;
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

//усовершенствованная сортировка обменом
void QuickSort(int array1[], int left, int right)
{
    int i = left, j = right;
    int pivot = array1[(left + right) / 2];
    int temp;
    while (i <= j)
    {
        comparisons++;
        while (array1[i] < pivot)
        {
            i++;
            comparisons++;
        }
        comparisons++;
        while (array1[j] > pivot)
        {
            j--;
            comparisons++;
        }
        if (i <= j)
        {
            temp = array1[i];
            array1[i] = array1[j];
            array1[j] = temp;
            exchanges += 3;
            i++;
            j--;
        }
        comparisons++;
    }

    if (left < j)
        QuickSort(array1, left, j);

    if (i < right)
        QuickSort(array1, i, right);
}

void QuickSortDialog()
{
    int* secarr = copy();
    int left = 0, right = length - 1;
    QuickSort(secarr, left, right);
    cout << "Количество сравнений " << comparisons << endl;
    cout << "Количество перестановок " << exchanges << endl;
    cout << "После сортирвки\n";
    print(secarr);
    delete[] secarr;
}

void heapify(int* arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    comparisons++;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    comparisons++;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        exchanges += 3;
        heapify(arr, n, largest);
    }
}

//усовершенствованная сортировка выбором
void heapSort(int n)
{
    int* secarr = copy();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(secarr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(secarr[0], secarr[i]);
        exchanges += 3;
        heapify(secarr, i, 0);
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
        cout << "4. Сортировка Шелла\n";
        cout << "5. Быстрая сортировка\n";
        cout << "6. Пирамидальная сортировка\n";
        cout << "7. Создать новый массив\n";
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
            Shell_sort();
        else if (comand == 5)
            QuickSortDialog();
        else if (comand == 6)
            heapSort(length);
        else if (comand == 7)
            creation();
        else if (comand == 0)
            break;
        else cout << "Такой команды нет\n\n";
    }

    delete[] arr;
    return 0;
}