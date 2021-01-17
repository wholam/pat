// 大整数运算
#include<iostream>
#include<vector>

using namespace std;

bool judge(vector<int>& s);//判断一个数是否是回文数
void change(vector<int>& s);
int main()
{
	long long int N;
	int K;
	cin >> N >> K;
	int a, step = 0;
	vector<int> s;
	vector<int> m;
	while (N != 0)
	{
		a = N % 10;
		N = N / 10;
		s.push_back(a);
	}
	while (judge(s) == false)
	{
		change(s);
		step++;
		if (step >= K)
			break;
	}
	for (int i = s.size()-1; i >= 0; i--)
		cout << s[i];
	cout << endl << step << endl;
	return 0;
}

void change(vector<int>& s)
{
	vector<int> m;
	int i = 0;
	for (i = s.size()-1; i >= 0; i--)
		m.push_back(s[i]);
	int c = 0;
	for (i = 0; i < s.size(); i++)
	{
		s[i] += m[i] + c;
		if (s[i] >= 10)
		{
			c = 1;
			s[i] -= 10;
		}
		else
			c = 0;
	}
	if (c == 1)
		s.push_back(1);
}

bool judge(vector<int>& s)//判断一个数是否是回文数
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}