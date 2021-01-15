#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

typedef struct record
{
	string plate_number;
	int time;
	string status;
	record(string tplate_number, int ttime, string tstatus) :
		plate_number(tplate_number), time(ttime), status(tstatus){};
	record() {};
}record;

bool cmp(record a, record b)
{
	return a.time < b.time;
}
typedef struct car
{
	string plate_number;
	int last_time=0;//持续时间
	record begin;
	bool flag = 0;//为1表示进入停车场
	car(string tplate_number) :plate_number(tplate_number) {};
}car;
bool cmp1(car a, car b)
{
	if (a.last_time != b.last_time)
		return a.last_time > b.last_time;
	else
		return a.plate_number < b.plate_number;
}
int main()
{
	int N, K;
	cin >> N >> K;
	int i, j;
	vector<record> info;
	vector<record> new_info;
	vector<int> query;
	string tplate_number, tstatus; int thh, tmm, tss, ttime;
	vector<car> cars;
	map<string, int> mp1;
	for (i = 0; i < N; i++)
	{
		cin >> tplate_number;
		scanf_s(" %d:%d:%d ", &thh, &tmm, &tss);
		ttime = thh * 3600 + tmm * 60 + tss;
		cin >> tstatus;
		info.push_back(record(tplate_number, ttime, tstatus));
	}
	for (i = 0; i < K; i++)
	{
		scanf_s("%d:%d:%d", &thh, &tmm, &tss);
		query.push_back(thh * 3600 + tmm * 60 + tss);
	}
	sort(info.begin(), info.end(), cmp);
	int num = 0;//车辆数
	string plate_number;
	for (i = 0; i < N; i++)
	{
		plate_number = info[i].plate_number;
		if (mp1[plate_number] == 0)
		{
			mp1[plate_number] = ++num;
			cars.push_back(car(plate_number));
		}
		if (info[i].status == "in")
		{
			cars[mp1[plate_number] - 1].begin = info[i];
			cars[mp1[plate_number] - 1].flag = 1;
		}
		else if(info[i].status == "out"  && cars[mp1[plate_number]-1].flag == 1)
		{
			new_info.push_back(cars[mp1[plate_number] - 1].begin);
			new_info.push_back(info[i]);
			cars[mp1[plate_number] - 1].flag = 0;
			cars[mp1[plate_number] - 1].last_time += info[i].time - cars[mp1[plate_number] - 1].begin.time;
		}
	}
	sort(new_info.begin(), new_info.end(), cmp);
	sort(cars.begin(), cars.end(), cmp1);
	num = 0;
	j = 0;
	for (i = 0; i < K; i++)
	{
		while (j < new_info.size() && new_info[j].time <= query[i])
		{
			if (new_info[j].status == "in")
				num++;
			else
				num--;
			j++;
		}
		cout << num << endl;
	}
	j = 1;
	thh = cars[0].last_time / 3600; tmm = (cars[0].last_time % 3600) / 60; tss = (cars[0].last_time % 60);
	cout << cars[0].plate_number << " ";
	while (j < cars.size() && cars[j].last_time == cars[0].last_time)
	{
		cout << cars[j].plate_number << " ";
		j++;
	}
	printf("%02d:%02d:%02d\n", thh, tmm, tss);
	return 0;
}