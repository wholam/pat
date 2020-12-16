#include<iostream>
#include<vector>

#define MAXN 510
#define INF 100000000
using namespace std;

struct MatGraph
{
	int weight[MAXN][MAXN];
	int n, e;
}g;
int bikes[MAXN];
int C, des;
vector<int> paths[MAXN];
vector<int> apath, path;
int sendnum=INF, backnum=INF;
void Dijkstra();
void CountPath(int dest);
int main()
{
	cin >> C >> g.n >> des >> g.e;
	int i,j;
	int a, b, c;
	for (i = 0; i <= g.n; i++)
		for (j = 0; j <= g.n; j++)
			g.weight[i][j] = INF;

	for (i = 1; i <= g.n; i++)
		cin >> bikes[i];
	bikes[0] = C / 2;
	for (i = 0; i < g.e; i++)
	{
		cin >> a >> b >> c;
		g.weight[a][b] = c;
		g.weight[b][a] = c;
	}
	Dijkstra();
	CountPath(des);
	cout << sendnum << " ";
	for (i = apath.size() - 1; i >= 0; i--)
		i == 0 ? cout << apath[i] << " " : cout << apath[i] << "->";
	cout << backnum << endl;
	return 0;
}
void Dijkstra()
{
	int visited[MAXN];
	int dist[MAXN];
	int i, j;
	for (i = 0; i <= g.n; i++)
	{
		visited[i] = 0;
		dist[i] = g.weight[0][i];
	}
	for (i = 0; i <= g.n; i++)
		if (g.weight[0][i] != INF)
			paths[i].push_back(0);
	visited[0] = 1;
	int mindex=-1;
	int min;
	int newlen;
	for (i = 1; i <= g.n; i++)
	{
		for (j = 1; j <= g.n; j++)
		{
			if (visited[j] == 0 && dist[j] < INF)
			{
				mindex = j;
				min = dist[j];
				break;
			}
		}
		if (mindex == -1)
			break;
		for (; j <= g.n; j++)
		{
			if (visited[j] == 0 && dist[j] < min)
			{
				mindex = j;
				min = dist[j];
			}
		}
		visited[mindex] = 1;
		for (j = 0; j <= g.n; j++)
		{
			if (visited[j] == 0 && g.weight[mindex][j] != INF)
			{
				newlen = min + g.weight[mindex][j];
				if (newlen < dist[j])
				{
					paths[j].clear();
					paths[j].push_back(mindex);
					dist[j] = newlen;
				}
				else if (newlen == dist[j])
					paths[j].push_back(mindex);
			}
		}
	}
}
void CountPath(int dest)
{
	path.push_back(dest);
	int send, back, need, index;
	int perfect = C / 2;
	int i, j;
	send = back = 0;
	if (dest == 0)
	{
		for (i = path.size()-2; i >= 0; i--)
		{
			index = path[i];
			if (bikes[index] > perfect)
				back += bikes[index] - perfect;
			else if (bikes[index] < perfect)
			{
				need = perfect - bikes[index];
				if (back >= need)
					back -= need;
				else
				{
					send += need - back;
					back = 0;
				}
			}
		}
		if (send < sendnum)
		{
			sendnum = send;
			backnum = back;
			apath = path;
		}
		else if (send == sendnum && back < backnum)
		{
			backnum = back;
			apath = path;
		}
		return;
	}
	int prev;
	for (i = 0; i < paths[dest].size(); i++)
	{
		prev = paths[dest][i];
		CountPath(prev);
		path.pop_back();
	}
}