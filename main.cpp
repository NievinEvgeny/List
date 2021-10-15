#include "adt.h"
#include <iostream>
using namespace std;

enum { STACK, QUEUE };

void printMenu()
{
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Вывести элементы\n";
    cout << "4. Удалить атд\n";
    cout << "5. Вывести кол-во элементов\n";
    cout << "6. Выход\n";
}

List* create(bool chosenAdt)
{
    switch (chosenAdt)
    {
    case STACK: {
        Stack* stack = new Stack;
        return stack;
    }
    case QUEUE: {
        Queue* queue = new Queue;
        return queue;
    }
    }
}

int main()
{
    List a(5);
    List b(a);
    a.Clear();
    b.Clear();

    cout << "'Stack = 0', 'Queue = 1'\n";
    bool chosenAdt;
    cin >> chosenAdt;

    int item;
    List* adt = create(chosenAdt);
    system("clear");
    while (item != 6)
    {
        printMenu();
        cin >> item;
        switch (item)
        {
        case 1:
            system("clear");
            int value;
            cout << "Введите значение элемента\n";
            cin >> value;
            adt->push(value);
            system("clear");
            break;
        case 2:
            system("clear");
            adt->pop();
            break;
        case 3:
            system("clear");
            adt->Print();
            break;
        case 4:
            system("clear");
            adt->Clear();
            break;
        case 5:
            system("clear");
            cout << adt->getCount() << "\n\n";
            break;
        }
    }
}