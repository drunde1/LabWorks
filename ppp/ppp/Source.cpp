#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>

int func()
{
    const int size = 1000000;
    int* array = new int[size];

    // «аполнение массива случайными числами
    auto start = std::chrono::high_resolution_clock::now();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100000);
    for (int i = 0; i < size; ++i) {
        array[i] = dis(gen);
    }

    // «амер времени выполнени€ сортировки

        std::sort(array, array + size);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << duration.count() << std::endl;
        return 0;
}

int main()
{
    for(int i = 0; i < 56; i++)
        func();
}