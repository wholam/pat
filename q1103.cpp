#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int n;//ȡֵ��ΧΪ1~n
int N, K, P;

void DFS(int index, int numK, int squareSum, int sum);
//index Ϊ��ǰ���������
//numK�Ѿ���������ָ���
//squareSum ƽ����
//sum ��

bool judge(vector<int>& a, vector<int>& b);//a>b�򷵻�true
vector<int> solution;
vector<int> current;
vector<int> current1;
int maxsum = 0;

int main()
{
	cin >> N >> K >> P;
	n = ceil(pow(N, 1.0/ P));
	DFS(n, 0, 0, 0);
	if (solution.size() == 0)
		cout << "Impossible" << endl;
	else
	{
		cout << N << " = ";
		for (int i = 0; i < K; i++)
		{
			if (i == K - 1)
				cout << solution[i] << "^" << P << endl;
			else
				cout << solution[i] << "^" << P << " + ";
		}
	}
	return 0;
}
void DFS(int index, int numK, int squareSum, int sum)
{
	if (index <=0)
		return;
	if (numK == K)
	{
		if (squareSum == N)
		{
			if (solution.size() == 0)
			{
				solution = current;
				maxsum = sum;
			}
			else
			{
				if (sum > maxsum)
				{
					solution = current;
					maxsum = sum;
				}
			}
		}
		return;
	}
	if (squareSum + pow(index, P) <= N)
	{
		current.push_back(index);
		DFS(index, numK + 1, squareSum + pow(index, P), sum + index);
		current.erase(current.end() - 1);
	}
	DFS(index - 1, numK, squareSum, sum);
}

bool judge(vector<int>& a, vector<int>& b)
{
	int i = 0;
	while (i < a.size() && i < b.size() && a[i] == b[i])
		i++;
	if (i == a.size())
		return false;
	if (i == b.size())
		return true;
	if (a[i] > b[i])
		return true;
	else
		return false;
}