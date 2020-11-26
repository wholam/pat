#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef struct person
{
	string name;
	int age;
	int worth;
}person;

bool cmp(person a, person b)
{
	if (a.worth != b.worth)
		return a.worth > b.worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return a.name < b.name;
}
typedef struct query
{
	int num;
	int amin;
	int amax;
}query;

int main()
{
	int N, K;
	int i, j;
	vector<person> info,info_tmp;
	vector<query> request;
	person tmp1;
	query tmp2;
	int age_num[200] = { 0 };
	cin >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> tmp1.name >> tmp1.age >> tmp1.worth;
		info.push_back(tmp1);
	}
	for (j = 0; j < K; j++)
	{
		cin >> tmp2.num >> tmp2.amin >> tmp2.amax;
		request.push_back(tmp2);
	}

	sort(info.begin(), info.end(), cmp);
	//进行预处理，将每个年龄排名在100名以外的人都去除掉，减少查询时间。
	for (j = 0; j < N; j++)
	{
		if (age_num[info[j].age-1] <= 100)
		{
			info_tmp.push_back(info[j]);
			age_num[info[j].age-1]++;
		}
	}

	int len = 0;
	for (i = 1; i <= K; i++)
	{
		cout << "Case #" << i << ":" << endl;
		len = 0;
		for (j = 0; j < info_tmp.size(); j++)
		{
			if (info_tmp[j].age >= request[i - 1].amin && info_tmp[j].age <= request[i - 1].amax && request[i-1].num>0)
			{
				cout << info_tmp[j].name << " " << info_tmp[j].age << " " << info_tmp[j].worth << endl;
				len++;
				request[i - 1].num--;
				if (request[i - 1].num == 0)
					break;
			}
		}
		if (len == 0)
			cout << "None" << endl;
	}
	return 0;
}