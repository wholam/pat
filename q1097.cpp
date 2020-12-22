//绝对值相等的数只保留第一次出现的，其余删除
#include<iostream>
#include<map>	
#include<vector>

using namespace std;

typedef struct node
{
	int addr, data, next;
	node() {};
	node(int taddr, int tdata, int tnext) :addr(taddr), data(tdata), next(tnext) {};
}node;
node list[100010];
int main()
{
	int begin, N;
	cin >> begin >> N;
	int i;
	int addr, data, next;
	vector<int> reserved, removed;
	map<int, int> mp;
	for (i = 0; i < N; i++)
	{
		cin >> addr >> data >> next;
		list[addr].addr = addr;
		list[addr].data = data;
		list[addr].next = next;
	}
	while (begin != -1)
	{
		if (mp[abs(list[begin].data)] == 0)
		{
			mp[abs(list[begin].data)] = 1;
			reserved.push_back(begin);
		}
		else
			removed.push_back(begin);
		begin = list[begin].next;
	}
	for (i = 0; i < reserved.size(); i++)
	{
		if (i == reserved.size() - 1)
			printf("%05d %d -1\n", reserved[i], list[reserved[i]].data);
		else
			printf("%05d %d %05d\n", reserved[i], list[reserved[i]].data,reserved[i+1]);
	}
	for (i = 0; i < removed.size(); i++)
	{
		if (i == removed.size() - 1)
			printf("%05d %d -1\n", removed[i], list[removed[i]].data);
		else
			printf("%05d %d %05d\n", removed[i], list[removed[i]].data, removed[i + 1]);
	}
	return 0;
}