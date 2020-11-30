#include<iostream>
#include<vector>	
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
vector<int> level;
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node node;
vector<int> origin;
node* create(int L, int R);
void levelorder(node* root);
int main()
{
	int N;
	cin >> N;
	int tmp;
	node* root;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		origin.push_back(tmp);
	}
	sort(origin.begin(), origin.end());
	root = create(0, N - 1);
	levelorder(root);
	for (int i = 0; i < N; i++)
		i == N - 1 ? cout << level[i] << endl : cout << level[i] << " ";
	return 0;
}
node* create(int L, int R)
{
	if (L > R)
		return NULL;
	else if (L == R)
	{
		node* root = new node;
		root->lchild = root->rchild = NULL;
		root->data = origin[L];
		return root;
	}
	int N = R - L + 1;
	int n = ceil(log(N + 1) / log(2)) - 1;
	int left;//左右子树的结点个数
	int a=0;
	for (int i = 0; i <= n - 2; i++)
		a += pow(2, i);
	if ((N - 1 - 2 * a) <= pow(2, n - 1))
		left = N - 1 - a;
	else
		left = a + pow(2, n - 1);
	node* root = new node;
	root->data = origin[L + left];
	root->lchild = create(L, L + left - 1);
	root->rchild = create(L + left + 1, R);
	return root;
}
void levelorder(node* root)
{
	if (root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		level.push_back(q.front()->data);
		if (q.front()->lchild != NULL)
			q.push(q.front()->lchild);
		if (q.front()->rchild != NULL)
			q.push(q.front()->rchild);
		q.pop();
	}
}