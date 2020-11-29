#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct node
{
	int data;
	int lchild;
	int rchild;
}tree[10];
int adata[10];
int index;
void levelorder(int root);
void inorder(int root);
int main()
{
	int i, N, root;
	cin >> N;
	char left, right;
	map<int, int> mp;
	for (i = 0; i < N; i++)
	{
		cin >> left >> right;
		tree[i].data = i;
		if (right != '-')
		{
			tree[i].lchild = right - 48;
			mp[right - 48] = 1;
		}
		else tree[i].lchild = -1;
		if (left != '-')
		{
			tree[i].rchild = left - 48;
			mp[left - 48] = 1;
		}
		else tree[i].rchild = -1;
	}
	root = -1;
	for(i=0;i<N;i++)
		if (mp[i] == 0)
			root = i;
	index = 0;
	levelorder(root);
	for (i = 0; i < N; i++)
		i == N - 1 ? cout << adata[i] << endl : cout << adata[i] << " ";
	index = 0;
	inorder(root);
	for (i = 0; i < N; i++)
		i == N - 1 ? cout << adata[i] << endl : cout << adata[i] << " ";
	return 0;
}
void levelorder(int root)
{
	queue<node> q;
	q.push(tree[root]);
	while (!q.empty())
	{
		adata[index++] = q.front().data;
		if (q.front().lchild != -1)
			q.push(tree[q.front().lchild]);
		if (q.front().rchild != -1)
			q.push(tree[q.front().rchild]);
		q.pop();
	}
}
void inorder(int root)
{
	if (root == -1)
		return;
	inorder(tree[root].lchild);
	adata[index++] = tree[root].data;
	inorder(tree[root].rchild);
}