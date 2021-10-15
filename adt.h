#pragma once

struct Node
{
    int value;
    struct Node* ptr;
};

class List
{
protected:
    Node* head;
    int count;

public:
    List(int c = 0);
    List(List& list);
    int getCount();
    bool isEmpty();
    int getValue(Node* node);
    Node* getFirst();
    Node* getLast();
    void Clear();
    Node* Next(Node* node);
    void Print();
    void pop();
    virtual void push(int value);
};

class Stack : public List
{
public:
    virtual void push(int value);
};

class Queue : public List
{
public:
    virtual void push(int value);
};