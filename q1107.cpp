#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

//typedef struct node
//{
//	set<int> s;
//	int num;
//}node;
//bool cmp(node a, node b)
//{
//	return a.num > b.num;
//}
//int main()
//{
//	int N, i, j, M;
//	vector<node> cluster;
//	cin >> N;
//	char a;
//	node tmp;
//	int tmp1;
//	set<int> c;
//	for (i = 0; i < N; i++)
//	{
//		tmp.num = 1;
//		tmp.s.clear();
//		cin >> M >> a;
//		for (j = 0; j < M; j++)
//		{
//			cin >> tmp1;
//			tmp.s.insert(tmp1);
//		}
//		if (i == 0)
//			cluster.push_back(tmp);
//		else
//		{
//			for (j = 0; j < cluster.size(); j++)
//			{
//				c.clear();
//				set_intersection(cluster[j].s.begin(), cluster[j].s.end(), tmp.s.begin(), tmp.s.end(), inserter(c, c.begin()));
//				if (c.size() != 0)
//				{
//					c.clear();
//					set_union(cluster[j].s.begin(), cluster[j].s.end(), tmp.s.begin(), tmp.s.end(), inserter(c, c.begin()));
//					tmp.s = c;
//					tmp.num += cluster[j].num;
//					cluster.erase(cluster.begin() + j);
//					j--;
//				}
//			}
//			cluster.push_back(tmp);
//		}
//	}
//	sort(cluster.begin(), cluster.end(), cmp);
//	cout << cluster.size() << endl;
//	for (i = 0; i < cluster.size(); i++)
//		i == cluster.size() - 1 ? cout << cluster[i].num << endl : cout << cluster[i].num << " ";
//	return 0;
//}

//接下来用并查集完成这道题目
int farther[1010];
int findFarther(int x)
{
	while (x != farther[x])
		x = farther[x];
	return x;
}
void Union(int a, int b)
{
	int farA = findFarther(a);
	int farB = findFarther(b);
	if (farA != farB)
		farther[farA] = farB;
}
int isRoot[1010] = {0};
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N, i, j, M;
	char a;
	cin >> N;
	int h;
	int hobby[1010];
	for (i = 0; i < 1010; i++)
		hobby[i] = 0;//记录一个兴趣是否已经出现了
	for (i = 0; i < 1010; i++)
		farther[i] = -1;
	for (i = 1; i <= N; i++)
	{
		cin >> M >> a;
		farther[i] = i;
		for (j = 0; j < M; j++)
		{
			cin >> h;
			if (hobby[h] == 0)
				hobby[h] = i;
			else
				Union(i, hobby[h]);
		}
	}
	for (int i = 1; i <= N; i++)
		if(findFarther(i) != -1)
			isRoot[findFarther(i)] ++;
	vector<int> tmp;
	int num = 0;
	for (int i = 1; i <= N; i++)
		if (isRoot[i] != 0)
		{
			num++;
			tmp.push_back(isRoot[i]);
		}
	sort(tmp.begin(), tmp.end(),cmp);
	cout << num << endl;
	for (i = 0; i < tmp.size(); i++)
		i == tmp.size() - 1 ? cout << tmp[i] << endl : cout << tmp[i] << " ";
	return 0;
}