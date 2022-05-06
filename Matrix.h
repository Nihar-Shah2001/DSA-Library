#pragma once
#include <iostream>
using namespace std;
struct Matrix
{
	int n=0;
	double* A=new double[n];
};
void DSet(Matrix* &m, double A[],int size) //Do something so that size is not required
{
	m->n = size;
	for (int i = 0; i < size; i++)
	{
		m->A[i] = A[i];
	}
}
double DGet(Matrix* &m, int i, int j)
{
	if (i == j)
		return m->A[i - 1];
	else
		return 0;
}
void DDisplay(Matrix* m)
{
	int i, j;
	for (i = 0; i < m->n; i++)
	{
		for (j = 0; j < m->n; j++)
		{
			if (i == j)
				cout << m->A[i] << " ";
			else
				printf("0 ");
		}
		printf("\n");
	}
}
void LowTSet(Matrix* &m, double A[], int size)
{
	int k = 0;
	m->n = (size * (size + 1)) / 2;
	for (int i = 0; i < size; i++)
	{
		m->A[i] = A[k];
		k++;
	}
}
double LowTGet(Matrix* &m, int i, int j)
{
	if (i >= j)
		return m->A[((i) * (i - 1)) / 2 + j - 1];
	else
		return 0;
}
void LowTDisplay(Matrix* m)
{
	int i, j;
	double k = (-1 + sqrt(1 + (8 * m->n))) / 2;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (i >= j)
				cout << m->A[((i + 1) * i) / 2 + j] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}
void UpTSet(Matrix*& m, double A[], int size)
{
	int k = 0;
	m->n = (size * (size + 1)) / 2;
	for (int i = 0; i < m->n; i++)
	{
		m->A[i] = A[k];
		k++;
	}
}
double UpTGet(Matrix*& m, int i, int j)
{
	if (i >= j)
		return m->A[((i) * (i - 1)) / 2 + j - 1];
	else
		return 0;
}
void UpTDisplay(Matrix* m)
{
	int i, j;
	double k = (-1 + sqrt(1 + (8 * m->n))) / 2;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (i <= j)
				cout << m->A[ (int(k) *i) - ((i-1)*(i))/2 + j-i] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}