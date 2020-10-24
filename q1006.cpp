#include<iostream>
#include<vector>
using namespace std;

typedef struct record
{
	char ID_number[15];
	int in_hour,in_minute,in_second;
	int out_hour, out_minute, out_second;
}record;
void input(int M, vector<record>&a)
{
	record temp;
	char b;
	for (int i = 0; i < M; i++)
	{
		cin >> temp.ID_number;
		cin >> temp.in_hour;
		cin >> b;
		cin >> temp.in_minute;
		cin >> b;
		cin >> temp.in_second;
		cin >> temp.out_hour;
		cin >> b;
		cin >> temp.out_minute;
		cin >> b;
		cin >> temp.out_second;
		a.push_back(temp);
	}
}
int main()
{
	int M;
	vector<record>a;
	cin >> M;
	input(M, a);
	int first_index=0,last_index=0;
	int first=0, last=0;
	int first_temp = 0, last_temp = 0;
	for (int i = 0; i < M; i++)
	{
		first = a[first_index].in_hour * 60 * 60 + a[first_index].in_minute * 60 + a[first_index].in_second;
		last = a[last_index].out_hour * 60 * 60 + a[last_index].out_minute * 60 + a[last_index].out_second;
		first_temp = a[i].in_hour * 60 * 60 + a[i].in_minute * 60 + a[i].in_second;
		last_temp = a[i].out_hour * 60 * 60 + a[i].out_minute * 60 + a[i].out_second;
		first_temp < first ? first_index = i : first_index = first_index;
		last_temp > last ? last_index = i : last_index = last_index;
	}
	cout << a[first_index].ID_number << " " << a[last_index].ID_number;
	return 0;
}