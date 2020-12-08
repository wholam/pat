#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	int data;
	int depth;
	node(int _data, int _depth) :data(_data), depth(_depth) {};
};
typedef struct node node;

int N, L;
vector<int> Adj[1001];
bool isvisited[1001];
int BFS(int root);
int main()
{
	vector<int> result;
	cin >> N >> L;
	int i, j, k, a, b;
	for (i = 0; i < N; i++)
	{
		cin >> j;
		for (k = 0; k < j; k++)
		{
			cin >> a;
			Adj[a].push_back(i + 1);
		}
	}
	cin >> a;
	for (i = 0; i < a; i++)
	{
		cin >> b;
		result.push_back(BFS(b));
		for (j = 0; j < 1001; j++)
			isvisited[j] = false;
	}
	for (i = 0; i < a; i++)
		cout << result[i] << endl;
	return 0;
}
int BFS(int root)
{
	isvisited[root] = true;
	queue<node> q;
	q.push(node(root, 0));
	node top(0, 0);
	node next(0, 0);
	int i;
	int sum = 0;
	while (!q.empty())
	{
		top = q.front();
		q.pop();
		for (i = 0; i < Adj[top.data].size(); i++)
		{
			if(isvisited[Adj[top.data][i]] == false)
			{
				next.data = Adj[top.data][i];
				next.depth = top.depth + 1;
				isvisited[next.data] = true;
				q.push(next);
				if (next.depth <= L)
					sum++;
			}
		}
	}
	return sum;
}