#include<iostream>
#include<vector>

#define MAXN 100 //最大结点个数
#define INF 100000
using namespace std;

typedef struct MatGraph
{
	int data[MAXN][MAXN] = { INF };//邻接矩阵
	int n;//结点个数
	int e;//边数
}MatGraph;

void Dijkstra(MatGraph& g, int v, int dist[MAXN], int paths[MAXN]);
void Dispaths(MatGraph& g, int v, int dist[MAXN], int paths[MAXN]);
int main()
{
	MatGraph g;
	cout << "请输入结点个数："; cin >> g.n;
	cout << "请输入边数："; cin >> g.e;
	int i, j;
	int a, b, w;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			g.data[i][j] = INF;
		g.data[i][i] = 0;
	}
	for (i = 0; i < g.e; i++)
	{
		cin >> a >> b >> w;
		g.data[a][b] = w;
	}
	int dist[MAXN], paths[MAXN];
	Dijkstra(g, 0, dist, paths);
	Dispaths(g, 0, dist, paths);
	return 0;
}

void Dijkstra(MatGraph& g, int v, int dist[MAXN], int paths[MAXN])
{
	int isvisited[MAXN];//为1表示在集合U中
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		dist[i] = INF;
		paths[i] = -1;
		isvisited[i] = 0;
	}
	isvisited[v] = 1;
	for (i = 0; i < g.n; i++)
	{
		if (g.data[v][i] != INF)
		{
			dist[i] = g.data[v][i];
			paths[i] = v;
		}
	}
	dist[v] = 0;
	int mindex;//存放V中路径最短的结点的编号
	int min;//存放最短路径
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
		isvisited[mindex] = 1;//将路径最短的结点加入集合U
		for (j = 0; j < g.n; j++)
		{
			if (isvisited[j] == 0 && g.data[mindex][j] != INF && dist[mindex] + g.data[mindex][j] < dist[j])//路径调整
			{
				dist[j] = dist[mindex] + g.data[mindex][j];
				paths[j] = mindex;
			}
		}
	}
}
void Dispaths(MatGraph& g, int v, int dist[MAXN], int paths[MAXN])
{
	int i, j, k;
	vector<int> path;
	for (i = 0; i < g.n; i++)
	{
		path.clear();
		if (paths[i] == -1 || i == v)
			continue;
		cout << "结点" << v << "到结点" << i << "路径长度为" << dist[i] << ",路径为：";
		j = i;
		do
		{
			k = j;
			path.push_back(k);
			j = paths[k];
		} while (j != k);
		for (j = path.size() - 1; j >= 0; j--)
			j == 0 ? cout << path[j] : cout << path[j] << "->";
		cout << endl;
	}
}