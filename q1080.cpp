#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct application
{
	int ge, gi;
	int total;
	int prefer[5];
	int rank;
	int id;
}application;

bool cmp(application a, application b)
{
	if (a.total != b.total)
		return a.total > b.total;
	else
		return a.ge > b.ge;
}
int main()
{
	int N, M, K;
	int capacity[100];//记录每个学校招生数
	int last_rank[100];//记录每个学校招的最后一个学生的排名
	vector<int> admitted[100];//记录每个学校录取情况
	cin >> N >> M >> K;
	int i, j;
	for (i = 0; i < M; i++)
		cin >> capacity[i];
	vector<application> info;
	application temp;
	for (i = 0; i < N; i++)
	{
		cin >> temp.ge >> temp.gi;
		temp.id = i;
		temp.total = temp.ge + temp.gi;
		for (j = 0; j < K; j++)
			cin >> temp.prefer[j];
		info.push_back(temp);
	}
	sort(info.begin(), info.end(), cmp);
	info[0].rank = 1;
	for (i = 1; i < N; i++)
	{
		if (info[i].total == info[i - 1].total && info[i].ge == info[i - 1].ge)
			info[i].rank = info[i - 1].rank;
		else
			info[i].rank = i + 1;
	}
	int want;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < K; j++)
		{
			want = info[i].prefer[j];
			if (capacity[want] > 0)
			{
				admitted[want].push_back(info[i].id);
				capacity[want] -= 1;
				last_rank[want] = info[i].rank;
				break;
			}
			else if(last_rank[want] == info[i].rank)
			{
				admitted[want].push_back(info[i].id);
				break;
			}
		}
	}
	for (i = 0; i < M; i++)
	{
		if (admitted[i].size() == 0)
			cout << endl;
		else
		{
			sort(admitted[i].begin(), admitted[i].end());
			for (j = 0; j < admitted[i].size(); j++)
			{
				if (j == admitted[i].size() - 1)
					cout << admitted[i][j] << endl;
				else
					cout << admitted[i][j] << " ";
			}
		}
	}
	return 0;
}