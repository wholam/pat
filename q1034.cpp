#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<iterator>

using namespace std;

int Adj[10001][10001];//邻接矩阵
bool isvisited[10001];//访问矩阵
int N = 0;//顶点个数
int E, K;//E为边数
map<string, int> mp;

bool BFS(int root, int& index, int& sum);
//index为weight最大的结点编号
//sum为该帮派的成员数
//若返回false，表示不满足成为一个帮派的条件

typedef struct node
{
	string name;
	int sum;
}node;
bool cmp(node a, node b)
{
	return a.name < b.name;
}
int main()
{
	cin >> E >> K;
	int i, j;
	string str1, str2;
	int a;
	vector<node> result;
	map<string, int>::iterator it;
	for (i = 0; i < E; i++)
	{
		cin >> str1 >> str2>>a;
		if (mp[str1] == 0)
			mp[str1] = ++N;
		if (mp[str2] == 0)
			mp[str2] = ++N;
		Adj[mp[str1]][mp[str2]] += a;
	}
	int index, sum;
	node tmp;
	int ans=0;//帮派个数
	for (i = 1; i <= N; i++)
	{
		if (isvisited[i] == false)
		{
			if (BFS(i, index, sum) != false)
			{
				ans++;
				tmp.sum = sum;
				for(it=mp.begin();it!=mp.end();it++)
					if (it->second == index)
					{
						tmp.name = it->first;
						break;
					}
				result.push_back(tmp);
			}
		}
	}
	cout << ans << endl;
	sort(result.begin(), result.end(), cmp);
	for (j = 0; j < result.size(); j++)
		cout << result[j].name << " " << result[j].sum << endl;
	return 0;
}
bool BFS(int root, int& index, int& sum)
{
	isvisited[root] = true;
	queue<int> q;
	index = root;
	int maxweight = 0;
	int i, j, k;
	for (i = 1; i <= N; i++)
	{
		maxweight += Adj[root][i];
		if (i != root)
			maxweight += Adj[i][root];
	}
	int totalweight = maxweight;
	sum = 1;
	q.push(root);
	int top;
	int tmpweight;
	while (!q.empty())
	{
		top = q.front();
		q.pop();
		for (i = 1; i <= N; i++)
		{
			if ((Adj[top][i] != 0 || Adj[i][top] != 0) && isvisited[i] == false)
			{
				sum++;
				isvisited[i] = true;
				tmpweight = 0;
				for (j = 1; j <= N; j++)
				{
					tmpweight += Adj[i][j];
					if (j != i)
						tmpweight += Adj[j][i];
				}
				totalweight += tmpweight;
				if (tmpweight > maxweight)
				{
					maxweight = tmpweight;
					index = i;
				}
				q.push(i);
			}
		}
	}
	totalweight = totalweight / 2;
	if (totalweight > K && sum > 2)
		return true;
	else
		return false;
}