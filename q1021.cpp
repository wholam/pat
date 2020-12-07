#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef struct node node;
vector<int> Adj[10010];
int isvisited[10010];
int N;

int BFS(int root);
int main()
{
	cin >> N;
	int i, j, k;
	int a, b;
	int result[10010];
	for (i = 0; i < N-1; i++)
	{
		cin >> a >> b;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	int ans = 0;
	for (k = 0; k <= N; k++)
		isvisited[k] = 0;
	for (j = 1; j <= N; j++)
	{
		if (isvisited[j] == 0)
		{
			BFS(j);
			ans++;
		}
	}
	if (ans > 1)
	{
		cout << "Error: "<<ans<<" components" << endl;
		return 0;
	}
	for (j = 1; j <= N; j++)
	{
		for (k = 0; k <= N; k++)
			isvisited[k] = 0;
		result[j] = BFS(j);
	}
	vector<int> maxindex;
	int max = result[1];
	maxindex.push_back(1);
	for (j = 2; j <= N; j++)
	{
		if (result[j] > max)
		{
			max = result[j];
			maxindex.clear();
			maxindex.push_back(j);
		}
		else if (result[j] == max)
			maxindex.push_back(j);
	}
	sort(maxindex.begin(), maxindex.end());
	for (j = 0; j < maxindex.size(); j++)
		cout << maxindex[j] << endl;
	return 0;
}
int BFS(int root)
{
	isvisited[root] = 1;
	queue<int> q;
	q.push(root);
	int top, next;
	int i;
	while (!q.empty())
	{
		top = q.front();
		q.pop();
		for (i = 0; i < Adj[top].size(); i++)
		{
			next = Adj[top][i];
			if (isvisited[next] == 0)
			{
				isvisited[next] = isvisited[top] + 1;
				q.push(next);
			}
		}
	}
	int max = isvisited[1];
	for (i = 2; i <= N; i++)
		if (isvisited[i] > max)
			max = isvisited[i];
	return max;
}