#pragma once
#include<iostream>
using namespace std;
struct DoublyLL
{
	DoublyLL* prev;
	long double data;
	DoublyLL* next;
};
void Display(DoublyLL* p)
{
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}
int Length(struct DoublyLL* p)
{
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}
void Insert(struct DoublyLL* &Head, int index,long double x)
{
	DoublyLL* p = Head;
	DoublyLL* t;
	int i;

	if (index < 0 || index > Length(p))
		return;
	if (index == 0)
	{
		t = new DoublyLL;
		t->data = x;
		t->prev = NULL;
		t->next = Head;
		Head->prev = t;
		Head = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t = new DoublyLL;
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if (p->next)
			p->next->prev = t;
		if (p)
		{
			p->next = t;
		}
	}
}
long double Delete(DoublyLL* Head, int index=0)
{
	DoublyLL* p = Head;
	double x = -1;
	if (index < 1 || index > Length(p))
		return 0;
	if (index == 1)
	{
		Head = Head->next;
		if (Head)
			Head->prev = NULL;
		x = p->data;
		delete p;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		(p->prev)->next = p->next;
		if (p->next)
			p->next->prev = p->prev;
		if (p)
		{
			x = p->data;
		}
		delete p;
	}
	return x;

}
void Reverse(DoublyLL* Head)
{
	DoublyLL* p = Head;
	struct DoublyLL* temp;

	while (p != NULL)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if (p != NULL && p->next == NULL)
			Head = p;
	}
}