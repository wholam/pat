#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

typedef struct testee {
	string registration_number;
	int location_number;
	int final_rank;
	int local_rank;
	int score;
}testee;
bool cmp(testee a, testee b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.registration_number < b.registration_number;
}
int main()
{
	int total_number = 0;
	int N,K;
	vector<testee> info;
	testee temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		if (K <= 0)
			continue;
		for(int j=0;j<K;j++)
		{
			cin >> temp.registration_number >> temp.score;
			temp.location_number = i+ 1;
			info.push_back(temp);
		}
		sort(info.end() - K, info.end(), cmp);
		info[total_number].local_rank = 1;
		for (int j = 1; j < K; j++)
		{
			if (info[total_number + j].score == info[total_number + j - 1].score)
				info[total_number + j].local_rank = info[total_number + j - 1].local_rank;
			else
				info[total_number + j].local_rank = j + 1;
		}
		total_number += K;
	}
	sort(info.begin(), info.end(), cmp);
	info[0].final_rank = 1;
	for (int j = 1; j < total_number; j++)
	{
		if (info[j].score == info[j - 1].score)
			info[j].final_rank = info[j - 1].final_rank;
		else
			info[j].final_rank = j + 1;
	}
	cout << total_number << endl;
	for (int i = 0; i < total_number; i++)
	{
		cout << info[i].registration_number << " " << info[i].final_rank << " "
			<< info[i].location_number << " " << info[i].local_rank << endl;
	}
	return 0;
}