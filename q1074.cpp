#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<iterator>
#include<iomanip>

using namespace std;

typedef struct node
{
	int addr, next;
	int data;
	node() {};
	node(int taddr, int tdata, int tnext) : addr(taddr), data(tdata), next(tnext) {};
}node;
int main()
{
	int root, N, K;
	cin >> root >> N >> K;
	int i, j;
	int addr, data, next;
	vector<node> list;
	vector<node> newlist;
	map<int, int> mp;//地址映射编号
	stack<node> s;
	node tmp;
	for (i = 0; i < N; i++)
	{
		cin >> addr >> data >> next;
		list.push_back(node(addr, data, next));
		if (mp[addr] == 0)
			mp[addr] = i;
	}
	int current, size;
	i = 0;
	while(root != -1)
	{
		current = mp[root];
		root = list[current].next;
		s.push(list[current]);
		if ((i + 1) % K == 0)
		{
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				newlist.push_back(tmp);
			}
		}
		else if (root == -1)//有效结点的最后一个结点
		{
			size = newlist.size();
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				newlist.insert(newlist.begin() + size, tmp);
			}
		}
		i++;
	}
	for (i = 0; i < newlist.size(); i++)
		i == newlist.size() - 1 ? cout << setw(5) << setfill('0') << newlist[i].addr << " " << newlist[i].data << " " << -1 << endl : cout << setw(5) << setfill('0') << newlist[i].addr << " " << newlist[i].data << " " << setw(5) << setfill('0') << newlist[i + 1].addr << endl;
	return 0;
}