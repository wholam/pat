#include<iostream>
#include<vector>
using namespace std;

int judge(int N);
int reverse(int N, int D);
int main()
{
	vector<int> a, b;
	int len = 0,temp,revnum;
	while (true)
	{
		cin >> temp;
		if (temp < 0)
			break;
		a.push_back(temp);
		cin >> temp;
		b.push_back(temp);
		len++;
	}
	for (int i = 0; i < len; i++)
	{
		if (judge(a[i]) == 0)
		{
			cout << "No" << endl;
			continue;
		}
		revnum = reverse(a[i], b[i]);
		if (judge(revnum) == 0)
		{
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
	}
	return 0;
}
int judge(int N)
{
	if (N == 1)
		return 0;
	if (N == 2)
		return 1;
	for (int i = 2; i < N; i++)
	{
		if (N % i == 0)
			return 0;
	}
	return 1;
}
int reverse(int N, int D)
{
	int a[20] = { 0 };//N最大10^5,二进制需要约20位
	int len = 0;
	while (N != 0)
	{
		a[len] = N % D;
		N = N / D;
		len++;
	}
	int start = 0, end = len - 1,temp;
	while (start < end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
	int sum = 0;
	for (int i = len-1; i >= 0; i--)
	{
		sum = sum * D;
		sum += a[i];
	}
	return sum;
}