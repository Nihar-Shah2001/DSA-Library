#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Term
{
	int coeff;
	int exp;
};
struct Poly
{
	int n;
	struct Term* terms;
};
void CreatePoly(Poly* p)
{
	int i;
	printf("Number of terms?");
	cin >> p->n;
	p->terms = new Term[p->n];

	printf("Enter terms\n");
	for (i = 0; i < p->n; i++)
		cin >> p->terms[i].coeff >> p->terms[i].exp;

}
void DisplayPoly(Poly p)
{
	int i;
	for (i = 0; i < p.n; i++)

		printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp);
	printf("\n");
}
Poly* addPoly(Poly* p1, Poly* p2)
{
	int i, j, k;
	struct Poly* sum;

	sum = new Poly;
	sum->terms = new Term[double(p1->n) + double(p2->n)];
	i = j = k = 0;

	while (i < p1->n && j < p2->n)
	{
		if (p1->terms[i].exp > p2->terms[j].exp)
			sum->terms[k++] = p1->terms[i++];
		else if (p1->terms[i].exp < p2->terms[j].exp)
			sum->terms[k++] = p2->terms[j++];
		else
		{
			sum->terms[k].exp = p1->terms[i].exp;
			sum->terms[k++].coeff = p1->terms[i ++].coeff + p2->terms[j++].coeff;
		}
	}
	for (; i < p1->n; i++)sum->terms[k++] = p1->terms[i];
	for (; j < p2->n; j++)sum->terms[k++] = p2->terms[j];

	sum->n = k;
	return sum;


}
long double EvalPoly(Poly* p,long double x)
{
	long double val = 0;
	for (int i = 0; i < p->n; i++)
	{
		val += p->terms[i].coeff * pow(x, p->terms[i].exp);
	}
	return val;
}