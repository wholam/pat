#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<int>& s, int L1, int R1, int L2, int R2);
int main()
{
	int N;
	int i, j, tmp;
	cin >> N;
	vector<int> s1, s2, s3;
	for (i = 0; i < N; i++)
	{
		cin >> tmp;
		s1.push_back(tmp);
	}
	for (i = 0; i < N; i++)
	{
		cin >> tmp;
		s2.push_back(tmp);
	}

	s3 = s1;
	bool flag = false;
	for (i = 1; i < N; i++)
	{
		tmp = s3[i];
		j = i;
		while (j > 0 && tmp < s3[j - 1])
		{
			s3[j] = s3[j - 1];
			j--;
		}
		s3[j] = tmp;
		for (j = 0; j < N; j++)
			if (s3[j] != s2[j])
				break;
		if (j == N)
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		if (i < N-1)
			sort(s3.begin(), s3.begin() + i + 2);
		cout << "Insertion Sort" << endl;
		for (int k = 0; k < s3.size(); k++)
		{
			if (k == s3.size() - 1)
				cout << s3[k] << endl;
			else
				cout << s3[k] << " ";
		}
		return 0;
	}
	s3 = s1;
	flag = false;
	int step;
	for (step = 2; step / 2 < N; step *= 2)
	{
		for (i = 0; i < N; i += step)
		{
			int mid = i - 1 + step / 2;
			if (mid + 1 < N)
				merge(s3, i, mid, mid + 1, min(N - 1, i + step - 1));
		}
		for (j = 0; j < N; j++)
			if (s3[j] != s2[j])
				break;
		if (j == N)
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		step *= 2;
		if (step / 2 < N)
		{
			for (i = 0; i < N; i += step)
			{
				int mid = i - 1 + step / 2;
				if (mid + 1 < N)
					merge(s3, i, mid, mid + 1, min(N - 1, i + step - 1));
			}
			cout << "Merge Sort" << endl;
			for (int k = 0; k < s3.size(); k++)
			{
				if (k == s3.size() - 1)
					cout << s3[k] << endl;
				else
					cout << s3[k] << " ";
			}
			return 0;
		}
	}
}
void merge(vector<int>& s, int L1, int R1, int L2, int R2)
{
	vector<int> m;
	int tmp = L1;
	while (L1 <= R1 && L2 <= R2)
	{
		if (s[L1] <= s[L2])
			m.push_back(s[L1++]);
		else
			m.push_back(s[L2++]);
	}
	while (L1 <= R1)
		m.push_back(s[L1++]);
	while (L2 <= R2)
		m.push_back(s[L2++]);
	for (int i = 0; i < m.size(); i++)
		s[tmp + i] = m[i];
}