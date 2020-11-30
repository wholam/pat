//按照BST先序序列的顺序建立的BST，它的先序序列与之前的先序序列相等。
#include<iostream>
#include<vector>

using namespace std;

vector<int> origin, pre, post, preM, postM;
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node node;
void insert(node*& root, int v);
void preorder(node* root);
void postorder(node* root);
void preorderM(node* root);
void postorderM(node* root);
int main()
{
	int N, i, j, tmp;
	cin >> N;
	node* root = NULL;
	for (i = 0; i < N; i++)
	{
		cin >> tmp;
		origin.push_back(tmp);
		insert(root, tmp);
	}
	preorder(root);
	preorderM(root);
	if (origin == pre)
	{
		cout << "YES" << endl;
		postorder(root);
		for (int i = 0; i < N; i++)
			i == N - 1 ? cout << post[i] << endl : cout << post[i] << " ";
	}
	else if (origin == preM)
	{
		cout << "YES" << endl;
		postorderM(root);
		for (int i = 0; i < N; i++)
			i == N - 1 ? cout << postM[i] << endl : cout << postM[i] << " ";
	}
	else
		cout << "NO" << endl;
	return 0;
}
void insert(node*& root,int v)
{
	if (root == NULL)
	{
		root = new node;
		root->lchild = root->rchild = NULL;
		root->data = v;
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
	pre.push_back(root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(node* root)
{
	if (root == NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
void preorderM(node* root)
{
	if (root == NULL)
		return;
	preM.push_back(root->data);
	preorderM(root->rchild);
	preorderM(root->lchild);
}
void postorderM(node* root)
{
	if (root == NULL)
		return;
	postorderM(root->rchild);
	postorderM(root->lchild);
	postM.push_back(root->data);
}