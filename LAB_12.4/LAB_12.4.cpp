#include <iostream>
#include <Windows.h>
using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;     // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень
Node* createList(int values[], int size) {
    Node* head = nullptr;  // Початковий вузол
    Node* tail = nullptr;  // Кінцевий вузол

    // Прохід по масиву значень
    for (int i = 0; i < size; i++) {
        // Створення нового вузла
        Node* newNode = new Node();
        newNode->data = values[i];  // Присвоєння значення вузлу
        newNode->prev = nullptr;    // Початкове значення вказівника на попередній вузол
        newNode->next = nullptr;    // Початкове значення вказівника на наступний вузол

        // Перевірка, чи це перший вузол у списку
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;  // Додавання нового вузла після кінцевого вузла
            newNode->prev = tail;  // Встановлення посилання на попередній вузол для нового вузла
            tail = newNode;        // Встановлення нового вузла як кінцевого
        }
    }

    return head;  // Повернення посилання на початковий вузол
}

// Функція для визначення, чи список містить пару сусідніх елементів з однаковими значеннями
bool containsAdjacentDuplicates(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку, за винятком останнього
    while (current->next != nullptr) {
        // Перевірка наявності сусідніх елементів з однаковими значеннями
        if (current->data == current->next->data) {
            return true;  // Пара сусідніх елементів з однаковими значеннями знайдена
        }
        current = current->next;  // Перехід до наступного вузла
    }

    return false;  // Пара сусідніх елементів з однаковими значеннями не знайдена
}

// Функція для виведення значень усіх вузлів у списку
void printList(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        cout << current->data << " ";  // Виведення значення поточного вузла
        current = current->next;       // Перехід до наступного вузла
    }

    cout << endl;  // Виведення символу нового рядка в кінці списку
}

// Функція для видалення всього списку та звільнення пам'яті
void deleteList(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        Node* temp = current;      // Тимчасовий вказівник на поточний вузол
        current = current->next;   // Перехід до наступного вузла
        delete temp;               // Звільнення пам'яті, що була виділена для поточного вузла
    }
}

int main() {

    int values[] = { 1, 2, 2, 3, 4, 5, 5, 6, 7 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву

    Node* head = createList(values, size);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printList(head);  // Виведення елементів списку

    // Перевірка наявності пари сусідніх елементів з однаковими значеннями
    if (containsAdjacentDuplicates(head)) {
        cout << "У списку є пара сусідніх елементів з однаковими значеннями." << endl;
    }
    else {
        cout << "У списку немає пари сусідніх елементів з однаковими значеннями." << endl;
    }

    deleteList(head);  // Видалення списку та звільнення пам'яті

    return 0;
}