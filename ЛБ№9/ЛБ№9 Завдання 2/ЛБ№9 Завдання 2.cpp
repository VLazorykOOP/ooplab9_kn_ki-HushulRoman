/*
Пояснення коду:

    Створюємо порожній вектор v та змінну n для збереження кількості елементів вектору, які будуть введені з клавіатури.
    Виводимо запит на введення кількості елементів вектору та зчитуємо значення в змінну n.
    Виводимо запит на введення елементів вектору та зчитуємо значення кожного елементу в циклі за допомогою функції push_back.
    Створюємо множину s для збереження унікальних елементів вектору.
    Видаляємо мінімальний та максимальний елементи з множини.
    Копіюємо залишок елементів множини у порядку спадання у новий вектор result за допомогою алгоритму copy та зворотніх ітераторів.
    Виводимо результат.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Точка входу в програму.
int main(int argc, char* argv[])
{
    //vector<int> v = { 3, 6, 2, 9, 1, 8, 5 };

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


    set<int> s(v.begin(), v.end()); // створюємо множину для збереження унікальних елементів
    s.erase(s.find(*min_element(v.begin(), v.end()))); // видаляємо мінімальний елемент
    s.erase(s.find(*max_element(v.begin(), v.end()))); // видаляємо максимальний елемент

    // копіюємо залишок елементів у порядку спадання у новий вектор
    vector<int> result;
    copy(s.rbegin(), s.rend(), back_inserter(result));

    // виводимо результат
    for (auto elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
