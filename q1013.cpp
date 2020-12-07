//求解连通分量的个数
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool isvisited[1000] = { false };
int tmp;
vector<int> Adj[1000];

void BFS(int i);
int main()
{
	int result[1000];
	int N, M, K;
	cin >> N >> M >> K;
	int i, j, k;
	int a, b;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	int ans = 0;
	for (i = 0; i < K; i++)
	{
		cin >> tmp;
		ans = 0;
		for (k = 0; k < 1000; k++)
			isvisited[k] = false;
		for (j = 1; j <= N; j++)
		{
			if (isvisited[j] == false)
			{
				BFS(j);
				ans++;
			}
		}
		result[i] = ans - 2;
	}
	for (j = 0; j < K; j++)
		cout << result[j] << endl;
	return 0;

}
void BFS(int i)
{
	isvisited[i] = true;
	if (i == tmp)
		return;
	queue<int> q;
	q.push(i);
	int top;
	int j, next;
	while (!q.empty())
	{
		top = q.front();
		q.pop();
		for (j = 0; j < Adj[top].size(); j++)
		{
			next = Adj[top][j];
			if (next == tmp)
				continue;
			if(isvisited[next] == false)
			{
				isvisited[next] = true;
				q.push(next);
			}
		}
	}
}