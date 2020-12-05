#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>

using namespace std;

typedef struct node
{
	double price;
	vector<int> child;
}node;
int main()
{
	int N;
	double P, r;
	cin >> N >> P >> r;
	node tmp;
	int i, j, k, m, n;
	node* tree = new node[N];
	int root;
	for (i = 0; i < N; i++)
	{
		cin >> n;
		if (n == -1)
		{
			root = i;
			continue;
		}
		tree[n].child.push_back(i);
	}
	tree[root].price = P;
	queue<int> q;
	q.push(root);
	double max = 0;
	int num = 0;
	while (!q.empty())
	{
		tmp = tree[q.front()];
		q.pop();
		if (tmp.child.size() == 0)
		{
			if (tmp.price > max)
			{
				max = tmp.price;
				num = 1;
			}
			else if (tmp.price == max)
				num++;
			continue;
		}
		for (k = 0; k < tmp.child.size(); k++)
		{
			tree[tmp.child[k]].price = tmp.price * (100 + r) / 100;
			q.push(tmp.child[k]);
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << max << " "<< num<<endl;
	return 0;
}