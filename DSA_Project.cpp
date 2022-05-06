#include "SinglyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "Matrix.h"
#include "Graphs.h"
#include "DoublyLInkedList.h"
#include "CircularLL.h"
#include "SparseMatrix.h"
#include "DoublyLInkedList.h"
#include "CircularLL.h"
#include<iostream>
int main()
{
	cout.setf(ios::boolalpha);
	/*bool quit = false;
	char choice;
	LList* root = NULL;
	cout << "Enter one of the following choices \n";
	cout << "1. Singly Linked List.\n";
	cout << "2. Stack\n";
	cout << "3. Queue\n";
	cout << "4. Matrix\n";
	cout << "5. ";
	cout << "Enter your choice here: ";
	cin >> choice;
	/*while (!quit)
	{
		bool quit1 = false;
		switch (choice)
		{
		case'1':
		{
			cout << "Enter the operation you wish to perfrom: ";
			char ch1;
			while (!quit1)
			{
				cout << "\n1. Insert\n";
				cout << "2. Display\n";
				cout << "3. Search\n";
				cout << "4. Length\n";
				cout << "5. Sum\n";
				cout << "6. Max\n";
				cout << "Enter your choice here: ";
				cin >> ch1;
				switch (ch1)
				{
				case'1':
				{
					cout << "Enter the  value to insert: ";
					long double ele;
					cin >> ele;
					LInsert(root, ele);
					break;
				}
				case'2':
				{
					Display(root);
					break;
				}
				case'3':
				{
					long double ele;
					cout << "Enter the value to search: ";
					cin >> ele;
					cout << LLSearch(root,ele);
					break;
				}
				case'4':
				{
					cout << length(root);
					break;
				}
				case'5':
				{
					cout << sum(root);
					break;
				}
				case'6':
				{
					cout << Max(root);
					break;
				}
				default:
				{
					quit1 = true;
					break;
				}
				}
			}
			break;
		}
		default:
		{
			quit = true;
			break;
		}
		}
	}*/
	/*LList* root = NULL;
	LLInsert(root, 2);
	LLInsert(root, 3);
	LLInsert(root, 4);
	LLInsert(root, 5);
	LLDisplay(root);
	cout<<"\n"<<LLDelete(root, 2);
	cout << "\n";
	LLDisplay(root);
	Stack* st=NULL;
	cout<<"\n"<<isEmpty(st);
	push(st, 2);
	push(st, 3);
	push(st, 4);
	Display(st);
	Queue* q=NULL;
	cout << "\n\n\n";
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 5);
	dequeue(q);
	Display(q);
	BTree* t = NULL;
	BTreeInsert(t, 30);
	BTreeInsert(t, 25);
	BTreeInsert(t, 50);
	BTreeInsert(t, 10);
	BTreeInsert(t, 28);
	BTreeInsert(t, 40);
	BTreeInsert(t, 60);
	cout << "\n\n\n";
	cout<<BTreeSearch(t, 29);
	cout << "\n\n";
	Preorder(t);
	cout << "\n\n";
	Postorder(t);
	cout << "\n\n";
	Inorder(t);
	double A[] = { 1,2,3,4,5,6,7,8,9,10 };
	Matrix* m = new Matrix;
	cout << "diagonal Matrix: \n";
	DSet(m, A, 10);
	DDisplay(m);
	cout << "Lower Traingular: \n";
	LowTSet(m, A, 4);
	cout << "\nDisplaying Matrix \n\n";
	LowTDisplay(m);
	cout << "\n\n\n";*/
	Matrix* m = new Matrix;
	double A[] = { 1,2,3,4 };
	DSet(m, A, 4);
	DDisplay(m);
	setGraph(m, 7);
	DisplayGraph(m);
	BFS(m, 3);
	DFS(m, 3);
	/*cout << LowTGet(m, 4, 4);
	UpTSet(m, A, 4);
	cout << "\n\n";
	UpTDisplay(m);*/
	//Poly* polynomial=NULL;
	//createPoly(polynomial);
	//DisplayPoly(polynomial);
	//cout<< Evaluate(polynomial, 1);
}