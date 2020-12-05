#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef struct node
{
	int weight;
	vector<int> child;
}node;
node tree[100];
vector<vector<int>> paths;
vector<string> paths_copy;
vector<int> path;
void findPaths(int start, int weight);
int S;

bool cmp(vector<int> a, vector<int> b)
{
	int i = 0;
	while (i < a.size() && i < b.size() && a[i] == b[i])
		i++;
	if (i < a.size() && i < b.size())
		return a[i] > b[i];
	else if (i == a.size())
		return false;
	else if (i == b.size())
		return true;
}
int main()
{
	int N, M;
	cin >> N >> M >> S;
	int i, j, k, m, n;
	for (i = 0; i < N; i++)
		cin >> tree[i].weight;
	for (i = 0; i < M; i++)
	{
		cin >> j >> k;
		for (m = 0; m < k; m++)
		{
			cin >> n;
			tree[j].child.push_back(n);
		}
	}
	findPaths(0, 0);
	sort(paths.begin(), paths.end(), cmp);
	for (i = 0; i < paths.size(); i++)
	{
		for (j = 0; j < paths[i].size(); j++)
		{
			j == paths[i].size() - 1 ? cout << paths[i][j] << endl : cout << paths[i][j] << " ";
		}
	}
	return 0;
}
void findPaths(int start, int weight)
{
	path.push_back(tree[start].weight);
	int w = weight + tree[start].weight;
	if (tree[start].child.size() == 0 && w == S)
	{
		paths.push_back(path);
		path.erase(path.end() - 1);
		return;
	}
	else if (tree[start].child.size() != 0 && w >= S)
	{
		path.erase(path.end() - 1);
		return;
	}
	for (int i = 0; i < tree[start].child.size(); i++)
		findPaths(tree[start].child[i], w);
	path.erase(path.end() - 1);
}
