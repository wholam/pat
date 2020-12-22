#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int capacity, N, K, tmp;
	cin >> capacity >> N >> K;
	vector<vector<int>> checks;
	vector<int> onecheck;
	int stack[1010];//ջ
	int top = -1;//ָ��ջ��
	int i, j;
	for (i = 0; i < K; i++)
	{
		onecheck.clear();
		for (j = 0; j < N; j++)
		{
			cin >> tmp;
			onecheck.push_back(tmp);
		}
		checks.push_back(onecheck);
	}
	int tostack;//��ǰҪ��ջ��Ԫ�أ� ��ջ���е�ǰԪ��
	bool flag;
	int next;
	for (i = 0; i < K; i++)
	{
		onecheck = checks[i];
		top = -1;
		tostack = 1;
		j = 0;
		flag = true;
		while (j < N)
		{
			next = ++top;
			if (next >= capacity)
			{
				flag = false;
				break;
			}
			stack[next] = tostack++;
			while (top != -1 && stack[top] == onecheck[j])
			{
				j++;
				top--;
			}
			if (top != -1 && stack[top] > onecheck[j])
			{
				flag = false;
				break;
			}
		}
		flag == false ? cout << "NO" << endl : cout << "YES" << endl;
	}
	return 0;
}