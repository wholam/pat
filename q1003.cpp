//到一个结点的最短路径可能有很多条
//用queue来存放每个结点的前一个结点
#include<iostream>
#include<vector>

#define INF 100000
#define MAXN 500

using namespace std;

typedef struct MatGraph
{
	int data[MAXN][MAXN];
	int n;//结点个数
	int e;//边数
}MatGraph;
void Dijkstra(MatGraph& g, int root);
void CountPaths(MatGraph& g, int root, int des, int tmp);
int num[MAXN];//每座城市救援队的数目
int pathnum = 0;//路径数目
int maxteam = 0;
vector<int> paths[MAXN];
int main()
{
	MatGraph g;
	cin >> g.n >> g.e;
	int root, des;
	cin >> root >> des;
	int i, j;
	int a, b, w;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.data[i][j] = INF;
	for (i = 0; i < g.n; i++)
		cin >> num[i];
	for (i = 0; i < g.e; i++)
	{
		cin >> a >> b >> w;
		g.data[a][b] = w;
		g.data[b][a] = w;
	}
	Dijkstra(g, root);
	CountPaths(g, root, des, 0);
	cout << pathnum << " " << maxteam << endl;
	return 0;
}
void Dijkstra(MatGraph& g, int root)
{
	int isvisited[MAXN];
	int dist[MAXN];

	int i, j;
	for (i = 0; i < g.n; i++)
	{
		isvisited[i] = 0;
		dist[i] = g.data[root][i];
		if (g.data[root][i] != INF)
			paths[i].push_back(root);
	}
	isvisited[root] = 1;
	paths[root].push_back(root);
	int mindex;
	int min;
	int newlen;
	for (i = 0; i < g.n - 1; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			if (isvisited[j] == 0)
			{
				mindex = j;
				min = dist[j];
				break;
			}
		}
		for (; j < g.n; j++)
		{
			if (isvisited[j] == 0 && dist[j] < min)
			{
				mindex = j;
				min = dist[j];
			}
		}
		isvisited[mindex] = 1;
		for (j = 0; j < g.n; j++)
		{
			if (isvisited[j] == 0 && g.data[mindex][j] != INF)
			{
				newlen = min + g.data[mindex][j];
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
void CountPaths(MatGraph& g, int root, int des, int tmp)
{
	tmp += num[des];
	if (des == root)
	{
		pathnum++;
		tmp > maxteam ? maxteam = tmp : maxteam = maxteam;
		return;
	}
	int i;
	for (i = 0; i < paths[des].size(); i++)
		CountPaths(g, root, paths[des][i], tmp);
}