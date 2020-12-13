#include<iostream>
#include<vector>

#define MAXN 500
#define INF 10000

using namespace std;

typedef struct MatGraph
{
	int distance[MAXN][MAXN];
	int weight[MAXN][MAXN];
	int n;
	int e;
}MatGraph;

vector<int> paths[MAXN];
void Dijkstra(MatGraph& g, int root);
void CountPath(MatGraph& g, int root, int des, int len, int cost);
vector<int> path;
int alen = 0;
int acost = 0;
vector<int> apath;
MatGraph g;
int main()
{
	int root, des;
	cin >> g.n >> g.e >> root >> des;
	int i, j;
	int a, b, c, d;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			g.distance[i][j] = INF;
		g.distance[i][i] = 0;
	}
	for (i = 0; i < g.e; i++)
	{
		cin >> a >> b >> c >> d;
		g.distance[a][b] = g.distance[b][a] = c;
		g.weight[a][b] = g.weight[b][a] = d;
	}
	Dijkstra(g, root);
	CountPath(g, root, des, 0, 0);
	for (i = apath.size() - 1; i >= 0; i--)
		cout << apath[i] << " ";
	cout << alen << " " << acost << endl;
	return 0;
}
void Dijkstra(MatGraph& g, int root)
{
	int visited[MAXN];
	int dist[MAXN];
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		visited[i] = 0;
		dist[i] = g.distance[root][i];
		if (g.distance[root][i] != INF)
			paths[i].push_back(root);
	}
	visited[root] = 1;
	int mindex;
	int min;
	int newlen;
	for (i = 0; i < g.n - 1; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			if (visited[j] == 0)
			{
				mindex = j;
				min = dist[j];
				break;
			}
		}
		for (; j < g.n; j++)
		{
			if (visited[j] == 0 && dist[j] < min)
			{
				mindex = j;
				min = dist[j];
			}
		}
		visited[mindex] = 1;
		for (j = 0; j < g.n; j++)
		{
			if (visited[j] == 0 && g.distance[mindex][j] != INF)
			{
				newlen = min + g.distance[mindex][j];
				if (newlen < dist[j])
				{
					paths[j] = vector<int>();
					paths[j].push_back(mindex);
					dist[j] = newlen;
				}
				else if (newlen == dist[j])
					paths[j].push_back(mindex);
			}
		}
	}
}
void CountPath(MatGraph& g, int root, int des, int len, int cost)
{
	path.push_back(des);
	if (des == root)
	{
		if (alen == 0 || cost < acost)
		{
			alen = len;
			acost = cost;
			apath = path;
		}
		return;
	}
	int prev;
	int i;
	int tmplen, tmpcost;
	for (i = 0; i < paths[des].size(); i++)
	{
		prev = paths[des][i];
		tmplen = len + g.distance[prev][des];
		tmpcost = cost + g.weight[prev][des];
		CountPath(g, root, prev, tmplen, tmpcost);
		path.pop_back();
	}
}