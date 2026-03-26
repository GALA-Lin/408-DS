#ifndef STACK_UTILS_H
#define STACK_UTILS_H

#include <iostream>
using namespace std;

#define ElemType int

#define MaxSize 100
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

void initStack(SqStack &S)
{
    S.top = -1;
}

bool isEmpty(SqStack S)
{
    return S.top == -1 ? true : false;
}

bool isFull(SqStack S)
{
    return S.top == MaxSize - 1 ? true : false;
}

void push(SqStack &S, ElemType x)
{
    if (isFull(S))
    {
        cout << "Stack is full!" << endl;
        return;
    }
    S.data[++S.top] = x;
}

void pop(SqStack &S, ElemType &x)
{
    if (isEmpty(S))
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    x = S.data[S.top--];
}

ElemType peek(SqStack S)
{
    if (isEmpty(S))
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return S.data[S.top];
}

void printStack(SqStack S)
{
    if (isEmpty(S))
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    for (int i = S.top; i >= 0; i--)
    {
        cout << S.data[i] << " ";
    }
    cout << endl;
}

#endif