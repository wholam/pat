#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
	int height;//树高
};
typedef struct node node;

void insert(node*& root, int v);
void SingleLeftRotation(node*& root);
void SingleRightRotation(node*& root);
void DoubleLeftRightRotation(node*& root);
void DoubleRightLeftRotation(node*& root);
int GetHeight(node* root);

int main()
{
	node* root = NULL;
	int N;
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		insert(root, tmp);
	}
	cout << root->data << endl;
	return 0;
}
int GetHeight(node* root)
{
	if (root == NULL)
		return 0;
	else
		return root->height;
}
void insert(node*& root, int v)
{
	if (root == NULL)
	{
		root = new node;
		root->lchild = root->rchild = NULL;
		root->data = v;
		root->height = 0;
	}
	else if (v < root->data)
	{
		insert(root->lchild, v);
		if (abs(GetHeight(root->lchild) - GetHeight(root->rchild)) == 2)
		{
			if (v < root->lchild->data)
				SingleLeftRotation(root);
			else
				DoubleLeftRightRotation(root);
		}
	}
	else
	{
		insert(root->rchild, v);
		if (abs(GetHeight(root->lchild) - GetHeight(root->rchild)) == 2)
		{
			if (v >= root->rchild->data)
				SingleRightRotation(root);
			else
				DoubleRightLeftRotation(root);
		}
	}
	root->height = max(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
}
void SingleLeftRotation(node*& root)
{
	//记得更新root和B的高度
	node* B = root->lchild;
	root->lchild = B->rchild;
	root->height = max(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
	B->rchild = root;
	root = B;
	root->height = max(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
}
void SingleRightRotation(node*& root)
{
	//记得更新root和B的高度
	node* B = root->rchild;
	root->rchild = B->lchild;
	root->height = max(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
	B->lchild = root;
	root = B;
	root->height = max(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
}
void DoubleLeftRightRotation(node*& root)
{
	SingleRightRotation(root->lchild);
	SingleLeftRotation(root);
}
void DoubleRightLeftRotation(node*& root)
{
	SingleLeftRotation(root->rchild);
	SingleRightRotation(root);
}