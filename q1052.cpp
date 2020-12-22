//��Ϊ���е�key�ǲ�ͬ�ģ�������������map��key�͵�ַ֮����ӳ��
//ע�⣺��������Ч���
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
typedef struct node
{
	int data, next, addr;
}node;
node list[100010];
int main()
{
	map<int, int> mp;
	vector<int> keys;	
	int root, N;
	cin >> N >> root;
	int addr, data, next;
	int i;
	bool flag = false;
	for (i = 0; i < N; i++)
	{
		cin >> addr >> data >> next;
		list[addr].addr = addr;
		list[addr].data = data;
		list[addr].next = next;
		if (addr == root)
			flag = true;
	}
	if (flag == false)
	{
		cout << "0 -1" << endl;
		return 0;
	}
	while (root != -1)
	{
		mp[list[root].data] = root;
		keys.push_back(list[root].data);
		root = list[root].next;
	}
	sort(keys.begin(), keys.end());
	int n = keys.size();
	printf("%d %05d\n", n, mp[keys[0]]);
	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
			printf("%05d %d -1\n", mp[keys[i]], keys[i]);
		else
			printf("%05d %d %05d\n", mp[keys[i]], keys[i], mp[keys[i+1]]);
	}
	return 0;
}