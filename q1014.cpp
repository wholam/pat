#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct customer
{
	int duration;//处理时间
	int end_time;//结束处理时间
	customer(int tduration) :duration(tduration) {};
	customer() {};
}customer;

typedef struct window
{
	int len = 0;//该窗口队列长度
	int next_time = 8 * 3600;//空闲开始时间
	int first_time = 8*3600;//每个窗口第一个人的服务结束时间
	queue<int> a;//服务队列
}window;

int main()
{
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	vector<customer> info;
	window* windows = new window [N];
	int* q = new int[Q];
	int i, j, tduration;
	for (i = 0; i < K; i++)
	{
		cin >> tduration;
		info.push_back(customer(tduration * 60));
	}
	for (i = 0; i < Q; i++)
		cin >> q[i];
	int min_len, min_first;//最短队列，最近服务时间
	int min_len_index, min_first_index;
	for (i = 0; i < K; i++)
	{
		min_len = windows[0].len; min_first = windows[0].first_time;
		min_len_index = 0; min_first_index = 0;
		for (j = 1; j < N; j++)
		{
			if (windows[j].len < min_len)
			{
				min_len = windows[j].len;
				min_len_index = j;
			}
			if (windows[j].first_time < min_first)
			{
				min_first = windows[j].first_time;
				min_first_index = j;
			}
		}
		if (min_len < M)
		{
			windows[min_len_index].next_time += info[i].duration;
			info[i].end_time = windows[min_len_index].next_time;
			if (min_len == 0)
				windows[min_len_index].first_time = info[i].end_time;
			windows[min_len_index].len++;
			windows[min_len_index].a.push(i);
		}
		else
		{
			windows[min_first_index].next_time += info[i].duration;
			info[i].end_time = windows[min_first_index].next_time;
			windows[min_first_index].a.pop();
			windows[min_first_index].a.push(i);
			windows[min_first_index].first_time = info[windows[min_first_index].a.front()].end_time;
		}
	}
	int time;
	int end = 17 * 3600;
	int hh, mm;
	for (i = 0; i < Q; i++)
	{
		time = info[q[i] - 1].end_time;
		if ((time - info[q[i]-1].duration) >= end)
			cout << "Sorry" << endl;
		else
		{
			hh = time / 3600;
			time = time % 3600;
			mm = time / 60;
			printf("%02d:%02d\n", hh, mm);
		}
	}
	return 0;
}