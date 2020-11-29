#include<iostream>
#include<string>
#include<queue>

using namespace std;

typedef struct opera
{
	string s;
	int data;
}opera;
queue<opera> info;
int index = 0;
int N;
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node node;

node* create();
void post(node* root);
int adata[30];
int ans = 0;
int main()
{
	int i;
	cin >> N;
	opera tmp;
	for (i = 0; i < 2 * N; i++)
	{
		cin >> tmp.s;
		if (tmp.s == string("Push"))
			cin >> tmp.data;
		info.push(tmp);
	}
	node* root;
	root = create();
	post(root);
	for (i = 0; i < N; i++)
		i == N - 1 ? cout << adata[i] : cout << adata[i] << " ";
	return 0;
}
node* create()
{
	if (index >= 2 * N)
		return NULL;
	if (info.front().s == "Pop")
	{
		index++;
		info.pop();
		return NULL;
	}
	node* root = new node;
	root->data = info.front().data;
	root->lchild = root->rchild = NULL;
	index++;
	info.pop();
	root->lchild = create();
	root->rchild = create();
	return root;
}
void post(node* root)
{
	if (root == NULL)
		return;
	post(root->lchild);
	post(root->rchild);
	adata[ans++] = root->data;
}