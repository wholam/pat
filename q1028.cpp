#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct student{
	string id;
	string name;
	int score;
}student;
bool cmp1(student a, student b)
{
	return a.id < b.id;
}
bool cmp2(student a, student b)
{
	if (a.name != b.name)
		return a.name < b.name;
	else
		return a.id < b.id;
}
bool cmp3(student a, student b)
{
	if (a.score != b.score)
		return a.score < b.score;
	else
		return a.id < b.id;
}
int main()
{
	vector<student> info;
	student temp;
	int N, C;
	cin >> N >> C;
	int i, j;
	for (i = 0; i < N; i++)
	{
		cin >> temp.id >> temp.name >> temp.score;
		info.push_back(temp);
	}
	switch (C)
	{
	case 1:
		sort(info.begin(), info.end(), cmp1);
		break;
	case 2:
		sort(info.begin(), info.end(), cmp2);
		break;
	case 3:
		sort(info.begin(), info.end(), cmp3);
	}
	for (j = 0; j < N; j++)
		cout << info[j].id << " " << info[j].name << " " << info[j].score << endl;
}