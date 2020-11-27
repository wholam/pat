#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef struct mooncake {
	double amount;
	double total_price;
	double price;
}mooncake;
bool cmp(mooncake a, mooncake b)
{
	return a.price > b.price;
}
int main()
{
	int N, D;
	double ans = 0;// ’“Ê
	vector<mooncake> m;
	mooncake tmp;
	cin >> N >> D;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> tmp.amount;
		m.push_back(tmp);
	}
	for (i = 0; i < N; i++)
	{
		cin >> m[i].total_price;
		m[i].price = m[i].total_price / m[i].amount;
	}
	sort(m.begin(), m.end(), cmp);
	for (i = 0; i < N; i++)
	{
		if (m[i].amount < D)
		{
			ans += m[i].total_price;
			D -= m[i].amount;
		}
		else
		{
			ans += D * m[i].price;
			break;
		}
	}
	cout <<setiosflags(ios::fixed)<<setprecision(2)<< ans << endl;
	return 0;
}