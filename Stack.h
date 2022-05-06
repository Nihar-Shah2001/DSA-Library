#pragma once
#include <stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
struct Stack
{
	long double data=0;
	Stack* next=NULL;
};
void push(Stack* &st,long double x)  //Pushes into top of stack
{
	Stack* t;
	t = new Stack;
	if (t == NULL)
		cout << "Stack is Full";
	else
	{
		t->data = x;
		t->next = st;
		st = t;
	}
}
long double pop(Stack* &st)  //deletes the top element
{
	Stack* t;
	long double x = -1;

	if (st == NULL)
		cout << "Stack is Empty!!";
	else
	{
		t = st;
		st = st->next;
		x = t->data;
		delete t;
	}
	return x;
}
long double peek(Stack* st)
{
	return st->data;
}
void Display(Stack* st)
{
	Stack* p;
	p = st;
	while (p != NULL)
	{
		cout << p->data<<" ";
		p = p->next;
	}
}
bool isEmpty(Stack* st)
{
	if (st == NULL)
		return true;
	else return false;
}