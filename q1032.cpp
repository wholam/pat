#include<iostream>
#include<iomanip>
#include<vector>

#define MAXN 100010

using namespace std;

typedef struct node
{
	int next;
	vector<int> belong;//记录每个结点所属根节点
}node;

node list[MAXN];

int main()
{
	int root1, root2, N;
	cin >> root1 >> root2 >> N;
	int i, j;
	int addr, next;
	char data;
	for (i = 0; i < N; i++)
	{
		cin >> addr >> data >> next;
		list[addr].next = next;
	}
	int root3;
	if (root1 == -1 || root2 == -1)
	{
		cout << -1 << endl;
		return 0;
	}
	else if (root1 == root2)
	{
		cout << setw(5) << setfill('0') << root1 << endl;
		return 0;
	}
	list[root1].belong.push_back(root1);
	int tmp = list[root1].next;
	while (tmp != -1)
	{
		list[tmp].belong.push_back(root1);
		tmp = list[tmp].next;
	}
	list[root2].belong.push_back(root2);
	tmp = list[root2].next;
	while (tmp != -1)
	{
		list[tmp].belong.push_back(root2);
		if (list[tmp].belong.size() == 2)
		{
			cout << setw(5) << setfill('0') << tmp << endl;
			return 0;
		}
		tmp = list[tmp].next;
	}
	cout << -1 << endl;
	return 0;
}