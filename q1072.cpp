//采用佛洛依德算法求出所有结点之间的最短距离，会超时
//采用Dijkstra算法
#include<iostream>
#include<set>
#include<string>
#include<map>
#include<sstream>
#include<iterator>
#include<iomanip>

#define MAXN 10100
#define INF 1000000
using namespace std;

typedef struct MatGraph
{
	int weight[MAXN][MAXN];
	int n;
	int m;
	int e;//边数
}MatGraph;
MatGraph g;

void Floyd(MatGraph& g);
void Dijkstra(int root, double& min, double& max, double& ave);
int main()
{
	map<string, int> mp;
	stringstream ss;
	set<int> gas;//存放站点下标
	int N, M, E, R;
	cin >> N >> M >> E >> R;
	g.n = N;	g.m = M;	g.e = E;
	int i, j, k;
	string a;
	int ta[2];
	int data;
	for (i = 1; i <= g.n + g.m; i++)
		for (j = 1; j <= g.n + g.m; j++)
			g.weight[i][j] = INF;
	for (i = 0; i < g.e; i++)
	{
		for(j=0;j<2;j++)
		{
			cin >> a;
			if (a[0] == 'G')
			{
				a = a.erase(0, 1);
				ss.clear();
				ss << a;
				ss >> ta[j];
				ta[j] += g.n;
				gas.insert(ta[j]);
			}
			else
			{
				ss.clear();
				ss << a;
				ss >> ta[j];
			}
		}
		cin >> data;
		g.weight[ta[0]][ta[1]] = g.weight[ta[1]][ta[0]] = data;
	}
	
	int index = -1;//存放一个站点到房子的最小、最大距离、总距离和下标
	double ave, min, max;
	double tmin, tmax, tave;//临时存放
	set<int>::iterator it = gas.begin();
	while (it != gas.end())
	{
		Dijkstra(*it, tmin, tmax, tave);
		if (tmax <= R)
		{
			if (index == -1 || tmin > min || (tmin == min && tave < ave))
			{
				min = tmin;
				max = tmax;
				ave = tave;
				index = *it;
			}
		}
		it++;
	}
	if (index == -1)
		cout << "No Solution" << endl;
	else
	{
		stringstream s1;
		s1 << 'G' << index - g.n;
		cout << s1.str() << endl;
		cout << setiosflags(ios::fixed) << setprecision(1);
		cout << min << " " << ave << endl;
	}
	return 0;
}
void Floyd(MatGraph& g)
{
	int i, j, k;
	int num = g.n + g.m;
	for(k=1;k<=num;k++)
		for(i=1;i<=num;i++)
			for (j = 1; j <= num; j++)
			{
				if (g.weight[k][i] + g.weight[k][j] < g.weight[i][j])
					g.weight[i][j] = g.weight[j][i] = g.weight[k][i] + g.weight[k][j];
			}
}

void Dijkstra(int root, double& min, double& max, double& ave)
{
	bool visited[MAXN];
	int dist[MAXN];
	int i, j, k;
	for (i = 1; i <= g.n + g.m; i++)
	{
		visited[i] = false;
		dist[i] = g.weight[root][i];
	}
	visited[root] = true;
	int u, newlen;
	for (i = 1; i < g.n + g.m - 1; i++)
	{
		u = -1;
		for (j = 1; j <= g.n + g.m; j++)
		{
			if (visited[j] == false && (u == -1 || (dist[j] < dist[u])))
				u = j;
		}
		visited[u] = true;
		for (j = 1; j <= g.n + g.m; j++)
		{
			if (visited[j] == false && g.weight[u][j] != INF)
			{
				newlen = dist[u] + g.weight[u][j];
				if (newlen < dist[j])
					dist[j] = newlen;
			}
		}
	}
	min = INF; max = 0;
	double sum = 0;
	for (i = 1; i <= g.n; i++)
	{
		sum += dist[i];
		if (dist[i] < min)
			min = dist[i];
		if (dist[i] > max)
			max = dist[i];
	}
	ave = sum / g.n;
}