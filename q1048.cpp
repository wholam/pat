#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<int, int> mp;
	int N, M;
	cin >> N >> M;
	int i, v1=0, v2=0;
	int tmp;
	for (i = 0; i < N; i++)
	{
		cin >> tmp;
		mp[tmp] ++;
	}
	map<int, int>::iterator it;
	int spare;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		spare = M - it->first;
		if (spare == it->first && mp[spare]>=2)
		{
				v1 = it->first;
				v2 = spare;
				break;
		}
		else if (spare > it->first && mp[spare] >= 1)
		{
			v1 = it->first;
			v2 = spare;
			break;
		}
	}
	if (v1 == 0)
		cout << "No Solution" << endl;
	else
		cout << v1 << " " << v2 << endl;
	return 0;
}