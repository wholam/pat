//最小生成树，prim算法和kruskal算法
#include<iostream>
#include<vector>
#include<algorithm>

#define MAXN 500
#define INF 10000000
using namespace std;

typedef struct edge
{
	int u, v;
	int cost;
	edge(int tu, int tv, int tcost) : u(tu), v(tv), cost(tcost) {};
	edge() {};
}enode;

typedef struct MatGraph
{
	int weight[MAXN][MAXN];
	vector<enode> edges;
	int n;
	int e;
}MatGraph;

bool cmp(enode a, enode b)
{
	return a.cost < b.cost;
}
int prim(MatGraph& g);//返回最小边权，-1表示图不连通
int kruskal(MatGraph& g);
int findFarther(int i, int farther[MAXN]);//找到结点i所在集合的根节点
int main()
{
	MatGraph g;
	cout << "请输入结点数："; cin >> g.n;
	cout << "请输入边数："; cin>> g.e;
	int i, j, k;
	int a, b, c;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			g.weight[i][j] = INF;
		g.weight[i][i] = 0;
	}
	for (i = 0; i < g.e; i++)
	{
		cin >> a >> b >> c;
		g.weight[a][b] = g.weight[b][a] = c;
		g.edges.push_back(enode(a, b, c));
	}
	cout << "prim算法结果："<< prim(g) << endl;
	cout << "kruskal算法结果：" << kruskal(g) << endl;
	return 0;
}
int prim(MatGraph& g)
{
	bool visited[MAXN];
	int i, j;
	int dist[MAXN];
	for (i = 0; i < g.n; i++)
	{
		visited[i] = false;
		dist[i] = INF;
	}
	dist[0] = 0;
	int u, v;
	int MIN;
	int ans = 0;//存放边权和
	for (i = 0; i < g.n; i++)
	{
		u = -1; MIN = INF;
		for (j = 0; j < g.n; j++)
		{
			if (visited[j] == false && dist[j] < MIN)
			{
				u = j;
				MIN = dist[j];
			}
		}
		if (u == -1) break;
		visited[u] = true;
		ans += dist[u];
		for (j = 0; j < g.n; j++)
		{
			if (visited[j] == false && g.weight[u][j] != INF && g.weight[u][j] < dist[j])
				dist[j] = g.weight[u][j];
		}
	}
	if (i != g.n)	return -1;
	else return ans;
}
int kruskal(MatGraph& g)
{
	int farther[MAXN];//并查集
	int i, j;
	for (i = 0; i < g.n; i++)
		farther[i] = i;
	sort(g.edges.begin(), g.edges.end(), cmp);
	int fu, fv;
	int num = 0;//记录已经加入的边的条数
	enode tmp;
	int ans = 0;//边权和
	for (i = 0; i < g.e; i++)
	{
		tmp = g.edges[i];
		fu = findFarther(tmp.u, farther);
		fv = findFarther(tmp.v, farther);
		if (fu != fv)
		{
			num++;
			ans += tmp.cost;
			farther[fv] = fu;
		}
		if (num == g.n - 1)	break;
	}
	if (num != g.n - 1) return -1;
	else return ans;
	return 0;
}
int findFarther(int i, int farther[MAXN])
{
	int x = i;
	while (x != farther[x])
		x = farther[x];

	int z = i;
	// 路径压缩
	while (i != x)
	{
		z = farther[i];
		farther[i] = x;
		i = z;
	}
	return x;
}
