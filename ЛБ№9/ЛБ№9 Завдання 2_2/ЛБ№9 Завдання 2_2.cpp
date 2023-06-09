﻿/*
Пояснення коду:

    Створюємо порожній вектор v та змінну n для збереження кількості елементів вектору, які будуть введені з клавіатури.
    Виводимо запит на введення кількості елементів вектору та зчитуємо значення в змінну n.
    Виводимо запит на введення елементів вектору та зчитуємо значення кожного елементу в циклі за допомогою функції push_back.
    Сортуємо вектор v за допомогою алгоритму sort.
    Знаходимо кінцеву позицію унікальних елементів у векторі за допомогою функції unique та зберігаємо її в змінну it.
    Видаляємо дубльовані елементи з вектору за допомогою функції erase.
    Видаляємо перший та останній елементи вектору за допомогою функції
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Точка входу в програму.
int main(int argc, char* argv[])
{
    //vector<int> v = { 5, 2, 8, 1, 9, 3 };

    vector<int> v;
    int n;

    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    cout << "Enter the elements of the vector: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "#" << (i + 1) << " ";
        int elem;
        cin >> elem;
        v.push_back(elem);
    }

    sort(v.begin(), v.end()); // сортуємо вектор
    auto it = unique(v.begin(), v.end()); // знаходимо кінцеву позицію унікальних елементів
    v.erase(it, v.end()); // видаляємо дубльовані елементи
    v.erase(v.begin()); // видаляємо перший елемент (мінімальний)
    v.erase(v.end() - 1); // видаляємо останній елемент (максимальний)
    sort(v.rbegin(), v.rend()); // сортуємо залишок елементів у порядку спадання

    // виводимо результат
    cout << "Result: ";
    for (auto elem : v) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
