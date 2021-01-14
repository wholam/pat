#include<iostream>
#include<algorithm>

using namespace std;

typedef struct student
{
	int id;
	int scores[6] = { -1, -1, -1, -1, -1, -1 };
	int total = 0;
	int perfect = 0;
	bool flag = false;
	int rank;
}student;
student info[10001];

bool cmp(student a, student b)
{
	if (a.total != b.total)
		return a.total > b.total;
	else if (a.perfect != b.perfect)
		return a.perfect > b.perfect;
	else
		return a.id < b.id;
}
int main()
{
	int full_mark[6];
	int N, K, M;
	cin >> N >> K >> M;
	int i, j;
	int id, index, score;
	for (i = 1; i <= K; i++)
		cin >> full_mark[i];
	for (i = 0; i < M; i++)
	{
		cin >> id >> index >> score;
		info[id].id = id;
		if (score == -1 && info[id].scores[index] == -1)
			info[id].scores[index] = 0;
		if (score > info[id].scores[index])
		{
			info[id].scores[index] = score;
			info[id].flag = true;
		}
	}
	for (i = 1; i <= N; i++)
	{
		for(j=1; j<=K; j++)
		{
			if(info[i].scores[j] != -1)
				info[i].total += info[i].scores[j];
			if (info[i].scores[j] == full_mark[j])
				info[i].perfect++;
		}
	}
	sort(info + 1, info + 1 + N, cmp);
	for (i = 1; i <= N; i++)
	{
		info[i].rank = i;
		if (i > 1)
		{
			if (info[i].total == info[i - 1].total)
				info[i].rank = info[i - 1].rank;
			else
				info[i].rank = i;
		}
	}
	for (i = 1; i <= N; i++)
	{
		if (info[i].flag == true)
		{
			printf("%d %05d %d ", info[i].rank, info[i].id, info[i].total);
			for (j = 1; j <= K; j++)
			{
				if (j == K)
				{
					if (info[i].scores[j] == -1)
						cout << "-" << endl;
					else
						cout << info[i].scores[j] << endl;
				}
				else
				{
					if (info[i].scores[j] == -1)
						cout << "-" << " ";
					else
						cout << info[i].scores[j] << " ";
				}
			}
		}
	}
	return 0;
}