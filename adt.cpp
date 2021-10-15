#include "adt.h"
#include <iostream>
using namespace std;

//конструкторы

List::List(int c) : head(NULL), count(c) //список инициализации
{
}

List::List(List& list) : head(list.head), count(list.count) //перегрузка
{
    cout << "АФЫХХАЫФХАФЫХАХФЫХАЫФХАХФЫХАФЫХАХФЫ\n";
}

//методы листа

int List ::getCount()
{
    return count;
}

bool List ::isEmpty()
{
    return head == NULL;
}

int List ::getValue(Node* node)
{
    return node->value;
}

Node* List ::getFirst()
{
    return head;
}

Node* List ::getLast()
{
    Node* node = head;
    while (Next(node) != NULL)
    {
        node = Next(node);
    }
    return node;
}

void List ::Clear()
{
    Node* node = head;
    if (node == NULL)
    {
        return;
    }
    while (node != NULL)
    {
        Node* d = node;
        node = Next(node);
        delete d;
    }
    count = 0;
    head = NULL;
}

Node* List ::Next(Node* node)
{
    if (isEmpty())
    {
        return NULL;
    }
    return node->ptr;
}

void List ::Print()
{
    if (isEmpty())
    {
        try
        {
            throw "Список пуст";
        }
        catch (const char* exception)
        {
            cerr << exception << "\n\n";
        }
        return;
    }
    Node* node = head;
    while (node != NULL)
    {
        cout << getValue(node) << " ";
        node = Next(node);
    }
    cout << "\n\n";
}

void List ::pop()
{
    if (isEmpty())
    {
        return;
    }
    count--;
    Node* temp = head->ptr;
    delete head;
    head = temp;
}

void List ::push(int value)
{
    return;
}

//удаление из стека

void Stack ::push(int value)
{
    count++;
    Node* elem = new Node();
    elem->value = value;
    if (head == NULL)
    {
        head = elem;
        elem->ptr = NULL;
        return;
    }
    else
    {
        elem->ptr = head;
        head = elem;
    }
}

//удаление из очереди

void Queue ::push(int value)
{
    count++;
    Node* elem = new Node();
    elem->value = value;
    if (head == NULL)
    {
        head = elem;
        elem->ptr = NULL;
        return;
    }
    else
    {
        Node* d = getLast();
        d->ptr = elem;
        elem->ptr = NULL;
    }
}