#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2); //输入带空格的字符串
	map<char, int> mp;
	int i = 0;
	for (i = 0; i < s2.size(); i++)
		mp[s2[i]] = 1;

	for (i = 0; i < s1.size(); i++)
		if (mp[s1[i]] == 0)
			cout << s1[i];
	return 0;
}