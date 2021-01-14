#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

typedef struct term
{
	int e;
	double c;
}term;

int main()
{
	int n1, n2, n3 = 0;//项数
	double coeff[1001] = { 0 };//0~1001次幂对应的系数
	int tempN;//幂
	double tempA;//系数
	vector<term> ploy;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> tempN;
		cin >> tempA;
		coeff[tempN] = tempA;
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> tempN;
		cin >> tempA;
		coeff[tempN] += tempA;
	}
	term temp;
	for (int i = 1000; i >= 0; i--)
	{
		if (coeff[i] != 0)
		{
			temp.e = i;
			temp.c = coeff[i];
			ploy.push_back(temp);
		}
	}
	if (ploy.size() == 0)
		cout << 0 << endl;
	else
	{
		cout << ploy.size() << " ";
		for (int j = 0; j < ploy.size(); j++)
		{
			if (j == ploy.size() - 1)
				cout << ploy[j].e << " " << setiosflags(ios::fixed)<<setprecision(1)<<ploy[j].c << endl;
			else
				cout << ploy[j].e << " " << setiosflags(ios::fixed) << setprecision(1)<<ploy[j].c << " ";
		}
	}
	return 0;
}