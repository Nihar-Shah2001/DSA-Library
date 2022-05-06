#pragma once
struct BTree
{
	long double data=0;
	BTree* lchild = NULL;
	BTree* rchild = NULL;
};
void BTreeInsert(BTree* &t,long double x)
{
	if (t==NULL)
	{
		t = new BTree;
		t->data = x;
	}
	else
	{
		BTree* p=NULL;
		BTree* k = t;
		BTree* z = new BTree;
		while (k)
		{
			if (k->data == x)
				return;
			else if (k->data < x)
			{
				p = k;
				k = k->rchild;
			}
			else
			{
				p = k;
				k = k->lchild;
			}
		}
		if (p->data > x)
		{
			z->data = x;
			p->lchild = z;
		}
		else
		{
			z->data = x;
			p->rchild = z;
		}
	}
}
void Preorder(BTree* p)
{
	if (p)
	{
		cout << p->data<<" ";
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}
void Inorder(BTree* p)
{
	if (p)
	{
		Inorder(p->lchild);
		cout << p->data<<" ";
		Inorder(p->rchild);
	}
}
void Postorder(BTree* p)
{
	if (p)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		cout << p->data << " ";
	}
}
bool BTreeSearch(BTree* t, long double x)
{
	while (t)
	{
		if (t->data == x)
			return true;
		else if (t->data < x)
		{
			t = t->rchild;
		}
		else t = t->lchild;
	}
	return false;
}