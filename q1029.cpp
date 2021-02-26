#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N[2];
	long int* s[2];
	for (int i = 0; i < 2; i++)
	{
		cin >> N[i];
		s[i] = new long int[N[i]];
		for (int j = 0; j < N[i]; j++)
			cin >> s[i][j];
	}
	vector<long int> m;
	int i, j;
	i = j = 0;
	while (i < N[0] && j < N[1])
	{
		if (s[0][i] < s[1][j])
			m.push_back(s[0][i++]);
		else if (s[0][i] == s[1][j])
		{
			m.push_back(s[0][i++]);
			j++;
		}
		else
			m.push_back(s[1][j++]);
	}
	while (i < N[0])
		m.push_back(s[0][i++]);
	while (j < N[1])
		m.push_back(s[1][j++]);
	cout << m[(m.size() - 1) / 2] << endl;
	return 0;
}