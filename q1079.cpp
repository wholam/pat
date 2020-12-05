#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>

using namespace std;

typedef struct node
{
	double price;
	int amount;
	vector<int> child;
}node;
int main()
{
	int N;
	double P, r;
	cin >> N >> P >> r;
	node tmp;
	int i, j, k,m, n;
	vector<node> tree;
	for (i = 0; i < N; i++)
	{
		tmp.child.clear();
		tmp.amount = -1;
		cin >> m;
		if (m == 0)
		{
			cin >> tmp.amount;
			tree.push_back(tmp);
			continue;
		}
		for (j = 0; j < m; j++)
		{
			cin >> n;
			tmp.child.push_back(n);
		}
		tree.push_back(tmp);
	}
	tree[0].price = P;
	queue<int> q;
	q.push(0);
	double ans = 0;
	while (!q.empty())
	{
		tmp = tree[q.front()];
		q.pop();
		if (tmp.child.size() == 0)
		{
			ans += tmp.amount * tmp.price;
			continue;
		}
		for (k = 0; k < tmp.child.size(); k++)
		{
			tree[tmp.child[k]].price = tmp.price * (100 + r) / 100;
			q.push(tmp.child[k]);
		}
	}
	cout << setiosflags(ios::fixed)<<setprecision(1) << ans << endl;
	return 0;
}