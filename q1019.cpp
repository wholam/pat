#include<iostream>
#include<vector>

using namespace std;

int main()
{
	unsigned int N, b, t;
	cin >> N >> b;
	vector<int> s;
	int a;
	while (N != 0)
	{
		a = N % b;
		N = N / b;
		s.push_back(a);
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s[s.size() - 1 - i])
		{
			cout << "No" << endl;
			for (int j = s.size()-1; j >= 0; j--)
			{
				if (j == 0)
					cout << s[j] << endl;
				else
					cout << s[j] << " ";
			}
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (int j = s.size() - 1; j >= 0; j--)
	{
		if (j == 0)
			cout << s[j] << endl;
		else
			cout << s[j] << " ";
	}
	return 0;
}