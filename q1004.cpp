#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct node
{
	vector<int> child;
	int level;
}node;
int main()
{
	int N, M;
	cin >> N >> M;
	node* tree = new node[N + 1];
	int i, j, tmp, seq, num;
	for (i = 0; i < M; i++)
	{
		cin >> seq >> num;
		for (j = 0; j < num; j++)
		{
			cin >> tmp;
			tree[seq].child.push_back(tmp);
		}
	}
	int* sum = new int[N + 1];
	queue<int> q;
	q.push(1);
	tree[1].level = 1;
	for (i = 0; i < N + 1; i++)
		sum[i] = 0;
	if (tree[1].child.size() == 0)
		sum[1] = 1;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		for (i = 0; i < tree[tmp].child.size(); i++)
		{
			j = tree[tmp].child[i];
			tree[j].level = tree[tmp].level + 1;
			if (tree[j].child.size() == 0)
				sum[tree[j].level] += 1;
			q.push(j);
		}
	}
	for (i = 1; i <= tree[N].level; i++)
		i == tree[N].level ? cout << sum[i] << endl : cout << sum[i] << " ";
	return 0;
}