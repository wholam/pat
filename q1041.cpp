#include<iostream>
#include<map>

using namespace std;

int main()
{
	int N;
	cin >> N;
	map<int, int> mp;
	int* p = new int[N];
	int i, j;
	for (i = 0; i < N; i++)
	{
		cin >> p[i];
		mp[p[i]] += 1;
	}
	for (i = 0; i < N; i++)
	{
		if (mp[p[i]] == 1)
		{
			cout << p[i] << endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;
}