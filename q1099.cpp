#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef struct node
{
	int data;
	int lchild;
	int rchild;
}node;
int N;
vector<node> tree;
vector<int> origin;
int index;
vector<int> level;
void build(int root);
void levelorder(int root);
int main()
{
	cin >> N;
	node tmp;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> tmp.lchild >> tmp.rchild;
		tree.push_back(tmp);
	}
	int a;
	for (i = 0; i < N; i++)
	{
		cin >> a;
		origin.push_back(a);
	}
	sort(origin.begin(), origin.end());
	build(0);
	levelorder(0);
	for (i = 0; i < N; i++)
		i == N - 1 ? cout << level[i] << endl : cout << level[i] << " ";
	return 0;
}
void build(int root)
{
	if (root == -1)
		return;
	if (tree[root].lchild == -1)
	{
		tree[root].data = origin[index++];
		build(tree[root].rchild);
	}
	else
	{
		build(tree[root].lchild);
		tree[root].data = origin[index++];
		build(tree[root].rchild);
	}
}
void levelorder(int root)
{
	if (root == -1)
		return;
	queue<node> q;
	q.push(tree[root]);
	node tmp;
	while (!q.empty())
	{
		tmp = q.front();
		level.push_back(tmp.data);
		if (tmp.lchild != -1)
			q.push(tree[tmp.lchild]);
		if (tmp.rchild != -1)
			q.push(tree[tmp.rchild]);
		q.pop();
	}
}