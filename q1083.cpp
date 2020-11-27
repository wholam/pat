#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef struct person
{
	string name;
	string id;
	int score;
}person;

bool cmp(person a, person b)
{
	return a.score > b.score;
}
int main()
{
	vector<person> info;
	person tmp;
	int n;
	int low, high;
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> tmp.name >> tmp.id >> tmp.score;
		info.push_back(tmp);
	}
	cin >> low >> high;
	int count = 0;
	sort(info.begin(), info.end(),cmp);
	for (i = 0; i < info.size(); i++)
	{
		if (info[i].score >= low && info[i].score <= high)
		{
			count++;
			cout << info[i].name << " " << info[i].id << endl;
		}
	}
	if (count == 0)
		cout << "NONE" << endl;
	return 0;
}