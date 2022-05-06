#pragma once
#include <iostream>
#include <cstdint>
using namespace std;
struct LList
{
	long double data=0;
	struct LList* next=NULL;
};
int length(LList* p)   //Length of a Linked List
{
	int l = 0;
	while (p)
	{
		l++;
		p = p->next;
	}
	return l;
}
void LLInsert(LList*& first, long double x, int index = 0)
{
	if (first == NULL)
	{
		first = new LList;
		first->data = x;
		return;
	}
	LList* t;
	LList* p = first;
	int i;

	if (index < 0 || index > length(p))
		return;
	t = new LList;
	t->data = x;
	if (index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;

	}
}
void LLDisplay(LList* p)   //Displays a Singly Linked List
{
	while (p != NULL)
	{
		cout << p->data <<" ";
		p = p->next;
	}
}
long double sum(LList* p) //returns Sum of the elements in Linked List
{
	long double s = 0;
	while (p != NULL)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}
LList* Max(LList* p) //RETURNS MAXIMUM ELEMENT FROM THE LINKED LIST
{
	long double max = INT64_MIN;
	while (p)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	return p;
}
bool LLSearch(LList* p, long double key) //Returns index position of the first occurence of element
{
	while (p)
	{
		if (key == p->data)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}
double LLDelete(LList* root, int index)
{
	LList* q = NULL;
	double x = -1;
	int i;
	if (index < 1 || index > length(root))
		return NULL;
	if (index == 1)
	{
		q = root;
		x = root->data;
		root = root->next;
		delete q;
		return x;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
		{
			q = root;
			root = root->next;
		}
		q->next = root->next;
		x = root->data;
		delete root;
		return x;
	}
}
bool LLisSorted(LList* p)
{
	double x = 0;
	while (p != NULL)
	{
		if (p->data < x)
			return false;
		x = p->data;
		p = p->next;
	}
	return true;

}
void LLRemoveDuplicate(LList* p)
{
	LList* q = p->next;
	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}

}
void ReverseLL(LList* p)
{
	double* A;
	int i = 0;
	LList* q = p;
	A = new double[length(p)];
	while (q != NULL)
	{
		*(A+i) = q->data;
		q = q->next;
		i++;
	}
	q = p;
	i--;
	while (q != NULL)
	{
		q->data = *(A +i);
		q = q->next;
		i--;
	}
}
void MergeLL(struct LList* p, struct LList* q)
{
	struct LList* last,*third;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		third->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}
	while (p && q)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;

		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;

		}
	}
	if (p)last->next = p;
	if (q)last->next = q;

}