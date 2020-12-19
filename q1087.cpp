#include<iostream>
#include<vector>
#include<map>
#include<iterator>

#define MAXN 200
#define INF 1000000

int index = 0;
using namespace std;

typedef struct MatGraph
{
	int weight[MAXN][MAXN];
	int n;
	int e;
}MatGraph;

int happiness[MAXN];
vector<int> paths[MAXN];
vector<int> path, tpath;
int num_of_path = 0;//最短路径条数
int acost, ahappiness, aave_of_happiness = -1;
void Dijkstra(MatGraph& g, int start);
void CountPath(MatGraph& g, int start, int des, int cost, int happiness);
int main()
{
	MatGraph g;
	map<string, int> mp;
	string a,b;
	int cost, happy;
	cin >> g.n >> g.e >> a;
	if (mp[a] == 0)
		mp[a] = index++;
	int start = mp[a], des;
	int i, j, k;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			g.weight[i][j] = INF;
		g.weight[i][i] = 0;
	}
	for (i = 1; i < g.n; i++)
	{
		cin >> a >> happy;
		mp[a] = index++;
		happiness[mp[a]] = happy;
		if (a == string("ROM"))
			des = mp[a];
	}
	for(i=0;i<g.e;i++)
	{
		cin >> a >> b >> cost;
		g.weight[mp[a]][mp[b]] = g.weight[mp[b]][mp[a]] = cost;
	}
	Dijkstra(g, start);
	CountPath(g, start, des, 0, happiness[des]);
	cout << num_of_path << " " << acost << " " << ahappiness << " " << aave_of_happiness << endl;
	map<string, int>::iterator it;
	for (i = path.size() - 1; i >= 0; i--)
	{
		it = mp.begin();
		while (it != mp.end())
		{
			if (it->second == path[i])
			{
				a = it->first;
				break;
			}
			it++;
		}
		if (i == 0)
			cout << a << endl;
		else
			cout << a << "->";
	}
	return 0;
}

void Dijkstra(MatGraph& g, int start)
{
	bool visited[MAXN];
	int dist[MAXN];
	int i, j, k;
	for (i = 0; i < g.n; i++)
	{
		visited[i] = false;
		dist[i] = g.weight[start][i];
		if (dist[i] != INF)
			paths[i].push_back(start);
	}
	visited[start] = true;
	int u, v, newlen;
	for (i = 1; i < g.n; i++)
	{
		u = -1;
		for (j = 0; j < g.n; j++)
		{
			if (visited[j] == false && dist[j] != INF && (u == -1 || dist[j] < dist[u]))
				u = j;
		}
		if (u == -1)
			break;
		visited[u] = true;
		for (j = 0; j < g.n; j++)
		{
			if (visited[j] == false && g.weight[u][j] != INF)
			{
				newlen = dist[u] + g.weight[u][j];
				if (newlen < dist[j])
				{
					paths[j].clear();
					paths[j].push_back(u);
					dist[j] = newlen;
				}
				else if (newlen == dist[j])
					paths[j].push_back(u);
			}
		}
	}
}
void CountPath(MatGraph& g, int start, int des, int cost, int happy)
{
	tpath.push_back(des);
	if (des == start)
	{
		num_of_path++;
		int ave_of_happiness = happy / (tpath.size()-1);
		if (aave_of_happiness == -1 || happy > ahappiness || (happy == ahappiness && ave_of_happiness > aave_of_happiness))
		{
			acost = cost;
			ahappiness = happy;
			aave_of_happiness = ave_of_happiness;
			path = tpath;
		}
		return;
	}
	int i, j, prev;
	int tcost, thappy;
	for (i = 0; i < paths[des].size(); i++)
	{
		prev = paths[des][i];
		tcost = cost + g.weight[des][prev];
		thappy = happy + happiness[prev];
		CountPath(g, start, prev, tcost, thappy);
		tpath.pop_back();
	}
}