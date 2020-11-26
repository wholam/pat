#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int K, temp, i;
	vector<int> num;
	cin >> K;
	for (i = 0; i < K; i++)
	{
		cin >> temp;
		num.push_back(temp);
	}
	int start,end,sum=0,j;
	if (K == 1 && num[0] >= 0)
		sum = num[0];
	start = 0;
	end = K - 1;
	int tempsum;
	i = 0;
	while (i < K)
	{
		j = i;
		tempsum = 0;
		while (j < K)
		{
			tempsum += num[j];
			if (tempsum > sum||(tempsum==sum&&tempsum==0))// 3 -1 -2 0 Õâ¸ö²âÊÔµã
			{
				sum = tempsum;
				start = i;
				end = j;
			}
			j++;
		}
		i++;
	}
	cout << sum << " " << num[start] << " " << num[end];
	return 0;
}
