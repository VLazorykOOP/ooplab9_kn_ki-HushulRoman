﻿/*
Цей код зчитує вхідні дані з файлу з назвою "Lab9_Task3_Data.txt", який містить послідовність записів про клієнтів фітнес-центру,
які складаються з чотирьох цілих чисел: код клієнта, тривалість занять, номер місяця та рік. Після зчитування даних програма виводить кількість місяців, у яких тривалість занять клієнта з кодом K перевищувала 15 годин, для кожного року, в якому клієнт відвідував центр. Результат виводиться на екран.

Для розв'язання задачі використовується структура даних Record, яка містить поля для зберігання даних про клієнта, а також оператор порівняння <,
щоб можна було використовувати функцію std::sort() для сортування записів за кількістю місяців занять клієнта з кодом K.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/*
Цей код оголошує структуру з назвою "Record", яка містить 4 поля типу int:

    client_code - код клієнта
    duration - тривалість занять клієнта (у годинах)
    month - номер місяця, в якому були заняття
    year - рік, в якому були заняття.

Це структура дозволяє зберігати інформацію про клієнтів фітнес-центру, включаючи код клієнта, тривалість занять, а також дату і час проведення цих занять.
*/
struct Record {
    int client_code;
    int duration;
    int month;
    int year;
};

/*
Ця функція перевантажує оператор порівняння "<" для структури "Record". Вона приймає два параметри типу "Record" (r1 та r2) та повертає значення типу "bool".

У тілі функції спочатку перевіряється, чи однакова тривалість занять у двох об'єктів "Record".
Якщо тривалість занять різна, то порівнюються значення поля "duration" в об'єктах r1 та r2:
якщо r1.duration більше, ніж r2.duration, то функція повертає true, що означає, що r1 < r2. Це означає,
що якщо клієнт r1 відвідав фітнес-центр більше годин, ніж клієнт r2, то r1 більш пріоритетний, ніж r2.

Якщо тривалість занять однакова у двох об'єктів, то порівнюються значення поля "year" в об'єктах r1 та r2.
Якщо r1.year менше, ніж r2.year, то функція повертає true, що означає, що r1 < r2.
Це означає, що якщо клієнти відвідали фітнес-центр протягом одного року та витратили однакову кількість годин,
то клієнт з меншим значенням "year" (більш новий) буде мати більший пріоритет.

Отже, ця функція допомагає впорядковувати список клієнтів фітнес-центру за зменшенням кількості затрачених годин,
а при однаковій кількості затрачених годин - за зростанням року.
*/
bool operator<(const Record& r1, const Record& r2) {
    if (r1.duration == r2.duration) {
        return r1.year < r2.year;
    }
    return r1.duration > r2.duration;
}

// Точка входу в програму.
int main(int argc, char* argv[])
{
    // Користувач вводить код клієнта k.
    int k;
    std::cout << "Enter client code: ";
    std::cin >> k;

    // Створюється вектор структур Record, що зберігатиме інформацію про клієнтів.
    std::vector<Record> records;

    // Відкривається файл "Lab9_Task3_Data.txt" для зчитування даних про клієнтів фітнес-центру.
    std::ifstream input("Lab9_Task3_Data.txt");

    // Якщо файл не відкривається, виводиться повідомлення про помилку та програма завершує роботу з кодом 1.
    if (!input) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    // Зчитування даних з файлу та додавання інформації про клієнтів з кодом k до вектору records.
    Record record;
    while (input >> record.client_code >> record.duration >> record.month >> record.year) {
        if (record.client_code == k) {
            records.push_back(record);
        }
    }

    // Якщо вектор records порожній, виводиться повідомлення "No data" та програма завершує роботу з кодом 0.
    if (records.empty()) {
        std::cout << "No data\n";
        return 0;
    }

    // Сортування вектору records в порядку спадання тривалості занять.
    std::sort(records.begin(), records.end());

    int current_year = records[0].year;
    int months_with_more_than_15_hours = 0;

    // Проходження по вектору records та підрахунок кількості місяців, в які клієнт відвідував фітнес-центр більше 15 годин за рік.
    for (const auto& r : records) {
        if (r.year != current_year) {
            std::cout << months_with_more_than_15_hours << " " << current_year << std::endl;
            current_year = r.year;
            months_with_more_than_15_hours = 0;
        }

        if (r.duration > 15) {
            months_with_more_than_15_hours++;
        }
    }

    std::cout << months_with_more_than_15_hours << " " << current_year << std::endl;

    return 0;
}
