#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct CircularLL
{
	long double data;
	CircularLL* next;
};
void Display(CircularLL* Head)
{
	CircularLL* h = Head;
	do
	{
		cout << h->data<<" ";
		h = h->next;
	} while (h != Head);
	cout << "\n";
}
int Length(CircularLL* Head)
{
	CircularLL* p = Head;
	int len = 0;
	do
	{
		len++;
		p = p->next;

	} while (p != Head);
	return len;
}
void CircularLLInsert(CircularLL* &Head,long double x,int index)
{
	CircularLL* t;
	CircularLL* p=Head;
	if (index<0 || index > Length(Head))
		return;
	if (index == 0)
	{
		if (Head == NULL)
		{
			Head = new CircularLL;
			Head->data = x;
			Head->next = Head;
		}
		else
		{
			while (p->next != Head)
				p = p->next;
			t = new CircularLL;
			t->data = x;
			p->next = t;
			t->next = Head;
			Head = t;
		}
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		t = new CircularLL;
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}
long double Delete(CircularLL* Head,int index=0)
{
	CircularLL* p = Head;
	CircularLL* q;
	long double i, x;

	if (index <0 || index >Length(Head))
		return -1;
	if (index == 1)
	{
		while (p->next != Head)p = p->next;
		x = Head->data;
		if (Head == p)
		{
			delete Head;
			Head = NULL;
		}
		else
		{
			p->next = Head->next;
			free(Head);
			Head = p->next;
		}
	}
	else
	{
		for (i = 0; i < double(index) - 2; i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		free(q);
	}
	return x;
}