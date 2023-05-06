/*
У цьому коді ми спочатку ввели число k, потім створили початковий вектор v.
Далі ми використали функцію std::search_n з параметрами v.begin() та v.end() для того, щоб знайти перший набір із k підряд розташованих додатніх чисел.
Цей пошук відбувається з використанням функціонального об'єкту, який перевіряє, що числа більше 0.

Якщо такий набір знайдено, ми використовуємо ітератори для того, щоб дублювати його у векторі.
Це відбувається за допомогою функції insert, яка вставляє копію набору між оригінальним набором та його копією.

У кінці ми виводимо змінений вектор за допомогою циклу for.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Точка входу в програму.
int main(int argc, char* argv[])
{
    int k;
    //std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Початковий вектор

    std::vector<int> v;
    int n;

    std::cout << "Enter the number of elements in the vector: ";
    std::cin >> n;

    std::cout << "Enter the elements of the vector: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "#" << (i + 1) << " ";
        int elem;
        std::cin >> elem;
        v.push_back(elem);
    }

    std::cout << "Enter K: ";
    std::cin >> k;

    // Шукаємо перший набір із K підряд розташованих додатніх чисел
    auto it = std::search_n(v.begin(), v.end(), k, 1, [](int x, int y) { return x > 0 && y > 0; });

    // Якщо знайдено такий набір
    if (it != v.end()) {
        // Обчислюємо ітератори на початок та кінець набору
        auto first = it;
        auto last = it + k;

        // Дублюємо набір у векторі
        v.insert(last, first, last);
    }

    // Виводимо вектор
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}