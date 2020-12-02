#include<iostream>
#include<stack>
#include<map>

using namespace std;

struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node node;

void preorder(node* root);
void inorder(node* root);
void postorder(node* root);
void insert(node*& root, int v);
int main()
{
	node* root = NULL;
	int tree[10] = { 43,12,34,65,76,83,45,46,87,29 };
	for (int i = 0; i <= 9; i++)
		insert(root, tree[i]);
	preorder(root);
	inorder(root);
	postorder(root);
	return 0;
}
void insert(node*& root, int v)
{
	if (root == NULL)
	{
		root = new node;
		root->data = v;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (v < root->data)
		insert(root->lchild, v);
	else
		insert(root->rchild, v);
}
void preorder(node* root)
{
	if (root == NULL)
		return;
	stack<node*> s;
	s.push(root);
	node* tmp;
	int data[10];
	int index = 0;
	while (!s.empty())
	{
		tmp = s.top();
		data[index++] = tmp->data;
		s.pop();
		if (tmp->rchild != NULL)
			s.push(tmp->rchild);
		if (tmp->lchild != NULL)
			s.push(tmp->lchild);
	}
	cout << "preorder:";
	for (int i = 0; i < 10; i++)
		i == 9 ? cout << data[i] << endl : cout << data[i] << " ";
}
void inorder(node* root)
{
	if (root == NULL)
		return;
	stack<node*> s;
	node* tmp;
	int data[10];
	int index = 0;
	node* p = root;
	while (p != NULL)
	{
		s.push(p);
		p = p->lchild;  //将左子节点入栈。
	}
	while (!s.empty())
	{
		tmp = s.top();
		s.pop();
		data[index++] = tmp->data;
		p = tmp->rchild;
		while (p != NULL)
		{
			s.push(p);
			p = p->lchild;
		}
	}
	cout << "inorder:";
	for (int i = 0; i < 10; i++)
		i == 9? cout << data[i] << endl : cout << data[i] << " ";
}
void postorder(node* root)
{
	if (root == NULL)
		return;
	node* tmp;
	stack<node*> s;
	int data[10];
	int index = 0;
	node* p = root;
	map<int, int> mp; //用map来记录某一结点之前是否被访问过。
	while (p != NULL)
	{
		s.push(p);
		p = p->lchild;
	}
	while (!s.empty())
	{
		tmp = s.top();
		if (mp[tmp->data] == 1)
		{
			data[index++] = tmp->data;
			s.pop();
		}
		else
		{
			mp[tmp->data] = 1;
			p = tmp->rchild;
			while (p != NULL)
			{
				s.push(p);
				p = p->lchild;
			}
		}
	}
	cout << "postorder:";
	for (int i = 0; i <= 9; i++)
		i == 9 ? cout << data[i] << endl : cout << data[i] << " ";
}
