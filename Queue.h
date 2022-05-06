#pragma once
#include<iostream>
using namespace std;
struct Queue
{
	long double data=0;
	Queue* next=NULL;

};
Queue* rear(Queue* q,Queue* r)
{
	while (q)
	{
		r = q;
		q = q->next;
	}
	return r;
}
void enqueue(Queue* &q,int x)
{
	Queue* t;
	Queue* r=new Queue;
	t = new Queue;
	if (t == NULL)
		cout << "Queue is full!";
	else
	{
		t->data = x;
		t->next = NULL;
		if (q == NULL)
			q = t;
		else
		{
			rear(q,r)->next = t;
		}
	}

}
long double dequeue(Queue* &q)
{
	long double x = -1;
	Queue* t;
	if (q == NULL)
		cout << "Queue is Empty";
	else
	{
		x = q->data;
		t = q;
		q = q->next;
		delete t;
	}
	return x;
}
void Display(Queue *q)
{
	Queue* p = q;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
bool isEmpty(Queue* q)
{
	if (q == NULL)
		return true;
	else return false;
}
long double peek(Queue* q)
{
	return q->data;
}