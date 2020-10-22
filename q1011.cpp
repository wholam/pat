#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int a[3];
	double odds[9];
	double sum;
	int j = 0;
	for (int i = 0; i < 9; i++)
		cin >> odds[i];
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 2)
		{
			a[j] = i;
			odds[i - 1] > odds[i] ? a[j]=i-1:a[j] = a[j];
			odds[i - 2] > odds[a[j]] ? a[j] = i - 2 : a[j] = a[j];
			if (a[j] % 3 == 0)
				cout << "W ";
			else if (a[j] % 3 == 1)
				cout << "T ";
			else
				cout << "L ";
			j++;
		}
	}
	sum = (odds[a[0]] * odds[a[1]] * odds[a[2]] * 0.65 - 1) * 2;
	cout << setprecision(4);//有效位数
	cout << sum;
	return 0;
}