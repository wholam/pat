#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef struct node
{
	int weight;
	int idx;//编号
	int rank;//排名
}node;
int main()
{
	int N, M;
	cin >> N >> M;
	node player[1000];
	int i, j;
	for (i = 0; i < N; i++)
	{
		cin >> player[i].weight;
		player[i].idx = i;
	}
	queue<int> q;//待处理的玩家的编号
	int num_this_turn;//参加该轮次的玩家数
	int num_out;//该轮次晋级玩家数
	int tmp;
	int max, max_index;
	vector<int> losers;//存放每轮被淘汰的玩家的编号
	for (i = 0; i < N; i++)
	{
		cin >> tmp;
		q.push(tmp);
	}
	num_this_turn = N;
	while (num_this_turn > 1)
	{
		num_out = 0;
		max = -1;
		losers.clear();
		for (j = 0; j < num_this_turn; j++)
		{
			tmp = q.front();
			q.pop();
			if (max == -1)
			{
				max = player[tmp].weight;
				max_index = tmp;
			}
			else if (player[tmp].weight > max)
			{
				losers.push_back(max_index);
				max = player[tmp].weight;
				max_index = tmp;
			}
			else if (player[tmp].weight < max)
			{
				losers.push_back(tmp);
			}
			if ((j+1) % M == 0 || j == num_this_turn - 1)
			{
				q.push(max_index);
				num_out++;
				max = -1;
			}
		}
		for (j = 0; j < losers.size(); j++)
			player[losers[j]].rank = num_out + 1;
		num_this_turn = num_out;
	}
	player[q.front()].rank = 1;
	q.pop();
	for (i = 0; i < N; i++)
		i == N - 1 ? cout << player[i].rank << endl : cout << player[i].rank << " ";
	return 0;
}