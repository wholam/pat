#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<char, int> mp;
	map<char, int> mp1;
	string s1, s2;
	cin >> s1 >> s2;
	char broken[80];
	int len = 0;
	int i, j;
	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	for (i = 1; i <= s2.size(); i++)
		mp[s2[i-1]] = i;
	for (i = 1; i <= s1.size(); i++)
	{
		if (mp[s1[i-1]] == 0 && mp1[s1[i-1]] == 0)
		{
			mp1[s1[i-1]] = i;
			cout << s1[i-1];
		}
	}
	return 0;
}