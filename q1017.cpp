#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<iomanip>

using namespace std;

typedef struct customer
{
	int arr_time;
	int proc_time;
	customer(int tarr_time, int tproc_time) :
		arr_time(tarr_time), proc_time(tproc_time) {};
	customer() {};
}customer;

bool cmp(customer a, customer b)
{
	return a.arr_time < b.arr_time;
}
int main()
{
	int N, K, i, j;
	cin >> N >> K;
	int begin, end;
	vector<customer> info;
	begin = 8 * 3600;
	end = 17 * 3600;
	int thh, tmm, tss, tproc, tarr_time, tproc_time;
	int num = 0;
	int total_time = 0;
	for (i = 0; i < N; i++)
	{
		scanf_s("%d:%d:%d %d", &thh, &tmm, &tss, &tproc);
		tarr_time = thh * 3600 + tmm * 60 + tss;
		tproc_time = tproc * 60;
		if (tarr_time <= end)
		{
			info.push_back(customer(tarr_time, tproc_time));
			num++;
		}
	}
	if (num == 0)//³ýÊýÎª0
	{
		cout << "0.0" << endl;
		return 0;
	}
	sort(info.begin(), info.end(), cmp);
	vector<int> s;
	for (i = 0; i < K; i++)
		s.push_back(0);
	for (i = 0; i < num; i++)
	{
		if (info[i].arr_time < begin)
		{
			total_time += begin - info[i].arr_time;
			info[i].arr_time = begin;
		}
		if (info[i].arr_time >= s[0])
		{
			s[0] = info[i].arr_time + info[i].proc_time;
		}
		else
		{
			total_time += (s[0] - info[i].arr_time);
			s[0] += info[i].proc_time;
		}
		sort(s.begin(), s.end());
	}
	double ave = total_time * 1.0 / (60*num);
	cout << setiosflags(ios::fixed) << setprecision(1) << ave << endl;
	return 0;
}