#include<iostream>
using namespace std;

int main()
{
	int N, a[100];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	int last = 0, next;
	int sum = 0,cost,step;
	for (int i = 0; i < N; i++)
	{
		next = a[i];
		step = next - last;
		step > 0 ? cost = 6 : cost = 4;
		step = abs(step);
		sum += cost * step + 5;
		last = next;
	}
	cout << sum;
	return 0;
}