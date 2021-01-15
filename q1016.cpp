#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#define MAXN 1000
using namespace std;

typedef struct record
{
	string name;
	int month, day, hour, minute;
	string status;
	record(string tname, int tmonth, int tday, int thour, int tminute, string tstatus) :
		name(tname), month(tmonth), day(tday), hour(thour), minute(tminute), status(tstatus){};
	record(){};
}record;

typedef struct bill
{
	int bday, bhour, bminute;
	int eday, ehour, eminute;
	int time;
	double cost=0;
	bill(int tbday, int tbhour, int tbminute, int teday, int tehour, int teminute, int ttime, double tcost) :
		bday(tbday), bhour(tbhour), bminute(tbminute), eday(teday), ehour(tehour), eminute(teminute), time(ttime), cost(tcost) {};
}bill;

typedef struct user
{
	string name;
	int month;
	vector<bill> bills;
	double totalcost=0;
}user;

bool cmp(record a, record b)
{
	if (a.day != b.day)
		return a.day < b.day;
	else if (a.hour != b.hour)
		return a.hour < b.hour;
	else
		return a.minute < b.minute;
}
bool cmp1(user a, user b)
{
	return a.name < b.name;
}
int cost[24];
vector<record> input[MAXN];
double count_cost(record& begin, record& end);
int main()
{
	int N, i, j, k;
	int num = 0;//ÓÃ»§Êı
	map<string, int> mp;
	for (i = 0; i < 24; i++)
		cin >> cost[i];
	cin >> N;

	string tname, tstatus;
	int tmonth, tday, thour, tminute;
	for (i = 0; i < N; i++)
	{
		cin >> tname;
		scanf_s(" %d:%d:%d:%d ", &tmonth, &tday, &thour, &tminute);
		cin >> tstatus;
		if (mp[tname] == 0)
		{
			mp[tname] = ++num;
			input[mp[tname]-1].push_back(record(tname, tmonth, tday, thour, tminute, tstatus));
		}
		else
			input[mp[tname]-1].push_back(record(tname, tmonth, tday, thour, tminute, tstatus));
	}
	user users[MAXN];
	record begin, end;
	int time;
	double bcost;
	for (i = 0; i < num; i++)
	{
		sort(input[i].begin(), input[i].end(), cmp);
		users[i].name = input[i][0].name;
		users[i].month = input[i][0].month;
		for (j = 0; j < input[i].size(); j++)
		{
			while (j < input[i].size() && input[i][j].status == "off-line")
				j++;
			if (j >= input[i].size())
				continue;
			begin = input[i][j];
			if ((j + 1) < input[i].size() && input[i][j + 1].status == "off-line")
			{
				end = input[i][j + 1];
				time = (end.day - begin.day) * 24 * 60 + (end.hour - begin.hour) * 60 + (end.minute - begin.minute);
				bcost = count_cost(begin, end);
				users[i].bills.push_back(bill(begin.day, begin.hour, begin.minute, end.day, end.hour, end.minute, time, bcost));
				users[i].totalcost += bcost;
			}
		}
	}
	sort(users, users + num, cmp1);
	for (i = 0; i < num; i++)
	{
		if (users[i].bills.size() == 0)
			continue;
		cout << users[i].name << " ";
		printf("%02d\n", users[i].month);
		for (j = 0; j < users[i].bills.size(); j++)
		{
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", users[i].bills[j].bday, users[i].bills[j].bhour, users[i].bills[j].bminute,
				users[i].bills[j].eday, users[i].bills[j].ehour, users[i].bills[j].eminute, users[i].bills[j].time, users[i].bills[j].cost);
		}
		printf("Total amount: $%.2f\n", users[i].totalcost);
	}
	return 0;
}

double count_cost(record& begin, record& end)
{
	double bcost = 0;
	int k, j;
	if (begin.day == end.day)
	{
		if (begin.hour == end.hour)
			bcost += (end.minute - begin.minute) * cost[begin.hour];
		else
		{
			for (k = begin.hour; k <= end.hour; k++)
			{
				if (k == begin.hour)
				{
					bcost += (60 - begin.minute) * cost[k];
				}
				else if (k == end.hour)
					bcost += end.minute * cost[k];
				else
					bcost += 60 * cost[k];
			}
		}
	}
	else
	{
		for (j = begin.day; j <= end.day; j++)
		{
			if (j == begin.day)
			{
				for (k = begin.hour; k <= 23; k++)
				{
					if (k == begin.hour)
					{
						bcost += (60 - begin.minute) * cost[k];
					}
					else
						bcost += 60 * cost[k];
				}
			}
			else if (j == end.day)
			{
				for (k = 0; k <= end.hour; k++)
				{
					if (k == end.hour)
					{
						bcost += end.minute * cost[k];
					}
					else
						bcost += 60 * cost[k];
				}
			}
			else
			{
				for (k = 0; k <= 23; k++)
					bcost += 60 * cost[k];
			}
		}
	}
	return bcost/100;
}
