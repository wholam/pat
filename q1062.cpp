#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iterator>

using namespace std;

typedef struct person
{
	string id;
	int virtue_grade;
	int talent_grade;
	int total_grade;
}person;

bool cmp(person a, person b)
{
	if (a.total_grade != b.total_grade)
		return a.total_grade > b.total_grade;
	else if (a.virtue_grade != b.virtue_grade)
		return a.virtue_grade > b.virtue_grade;
	else
		return a.id < b.id;
}
int main()
{
	vector<person> sage;
	vector<person> noble;
	vector<person> fool;
	vector<person> small;
	person tmp;
	int M, L, H;
	cin >> M >> L >> H;
	int i,N=0;
	for (i = 0; i < M; i++)
	{
		cin >> tmp.id >> tmp.virtue_grade >> tmp.talent_grade;
		tmp.total_grade = tmp.virtue_grade + tmp.talent_grade;
		if (tmp.virtue_grade >= L && tmp.talent_grade >= L)
		{
			N++;
			if (tmp.virtue_grade >= H && tmp.talent_grade >= H)
				sage.push_back(tmp);
			else if (tmp.virtue_grade >= H)
				noble.push_back(tmp);
			else if (tmp.virtue_grade >= tmp.talent_grade && tmp.virtue_grade < H)
				fool.push_back(tmp);
			else
				small.push_back(tmp);
		}
	}
	sort(sage.begin(), sage.end(), cmp);
	sort(noble.begin(), noble.end(), cmp);
	sort(fool.begin(), fool.end(), cmp);
	sort(small.begin(), small.end(), cmp);

	vector<person>::iterator it;
	cout << N << endl;
	for (it = sage.begin(); it != sage.end(); it++)
		cout << it->id << " " << it->virtue_grade << " " << it->talent_grade << endl;
	for (it = noble.begin(); it != noble.end(); it++)
		cout << it->id << " " << it->virtue_grade << " " << it->talent_grade << endl;
	for (it = fool.begin(); it != fool.end(); it++)
		cout << it->id << " " << it->virtue_grade << " " << it->talent_grade << endl;
	for (it = small.begin(); it != small.end(); it++)
		cout << it->id << " " << it->virtue_grade << " " << it->talent_grade << endl;
	return 0;
}