#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

typedef struct student
{
	string id;
	int scores[4];
	int rank[4];
	int trank;
	char tsub;
}student;

bool cmp1(student a, student b)
{
	return a.scores[0] > b.scores[0];
}
bool cmp2(student a, student b)
{
	return a.scores[1] > b.scores[1];
}
bool cmp3(student a, student b)
{
	return a.scores[2] > b.scores[2];
}
bool cmp4(student a, student b)
{
	return a.scores[3] > b.scores[3];
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<student> info;
	vector<string> request;
	student temp;
	string s1;
	int i;
	map<string, int> mp;
	for (i = 0; i < N; i++)
	{
		cin >> temp.id >> temp.scores[0] >> temp.scores[1] >> temp.scores[2];
		temp.scores[3] = (temp.scores[0] + temp.scores[1] + temp.scores[2]) / 3;
		info.push_back(temp);
	}
	for (i = 0; i < M; i++)
	{
		cin >> s1;
		request.push_back(s1);
	}
	if (N == 0)
	{
		for (i = 0; i < M; i++)
			cout << "N/A" << endl;
		return 0;
	}
	sort(info.begin(), info.end(), cmp1);
	int rank = 1;
	info[0].rank[0] = rank;
	for (i = 1; i < N; i++)
	{
		if (info[i].scores[0] == info[i - 1].scores[0])
			info[i].rank[0] = rank;
		else
		{
			rank = i + 1;
			info[i].rank[0] = rank;
		}
	}

	sort(info.begin(), info.end(), cmp2);
	rank = 1;
	info[0].rank[1] = rank;
	for (i = 1; i < N; i++)
	{
		if (info[i].scores[1] == info[i - 1].scores[1])
			info[i].rank[1] = rank;
		else
		{
			rank = i + 1;
			info[i].rank[1] = rank;
		}
	}

	sort(info.begin(), info.end(), cmp3);
	rank = 1;
	info[0].rank[2] = rank;
	for (i = 1; i < N; i++)
	{
		if (info[i].scores[2] == info[i - 1].scores[2])
			info[i].rank[2] = rank;
		else
		{
			rank = i + 1;
			info[i].rank[2] = rank;
		}
	}

	sort(info.begin(), info.end(), cmp4);
	rank = 1;
	info[0].rank[3] = rank;
	mp[info[0].id] = 1;
	for (i = 1; i < N; i++)
	{
		mp[info[i].id] = i + 1;
		if (info[i].scores[3] == info[i - 1].scores[3])
			info[i].rank[3] = rank;
		else
		{
			rank = i + 1;
			info[i].rank[3] = rank;
		}
	}

	for (i = 0; i < N; i++)
	{
		info[i].trank = info[i].rank[3];
		info[i].tsub = 'A';
		if (info[i].rank[0] < info[i].trank)
		{
			info[i].trank = info[i].rank[0];
			info[i].tsub = 'C';
		}
		if (info[i].rank[1] < info[i].trank)
		{
			info[i].trank = info[i].rank[1];
			info[i].tsub = 'M';
		}
		if (info[i].rank[2] < info[i].trank)
		{
			info[i].trank = info[i].rank[2];
			info[i].tsub = 'E';
		}
	}
	for (i = 0; i < M; i++)
	{
		s1 = request[i];
		if (mp[s1] == 0)
			cout << "N/A" << endl;
		else
			cout << info[mp[s1]-1].trank << " " << info[mp[s1]-1].tsub << endl;
	}
	return 0;
}