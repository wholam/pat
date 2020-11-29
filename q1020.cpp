#include<iostream>
#include<queue>

using namespace std;

struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node node;

node* create(int postL, int postR, int inL, int inR);
void level(node*& root);
int postorder[30], inorder[30];
int main()
{
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> postorder[i];
	for (i = 0; i < N; i++)
		cin >> inorder[i];
	node* root = create(0,N-1,0,N-1);
	level(root);
	return 0;
}

node* create(int postL, int postR, int inL, int inR)
{
	if (postL > postR)
		return NULL;
	int k;
	for (k = inL; k <= inR; k++)
		if (inorder[k] == postorder[postR])
			break;
	node* root = new node;
	root->data = inorder[k];
	root->lchild = create(postL, postL + k - inL -1, inL, k-1);
	root->rchild = create(postL+k-inL, postR - 1, k+1, inR);
	return root;
}
void level(node*& root)
{
	queue<node*> q;
	if (root == NULL)
		return;
	q.push(root);
	node* tmp;
	while (!q.empty())
	{
		tmp = q.front();
		if (tmp->lchild != NULL)
			q.push(tmp->lchild);
		if (tmp->rchild != NULL)
			q.push(tmp->rchild);
		q.pop();
		q.empty() ? cout << tmp->data : cout << tmp->data << " ";
	}
}