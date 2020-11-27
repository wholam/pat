#include<iostream>
#include<vector>
#include<algorithm>	
using namespace std;
vector<int> num;
int binarysearch(long long m,int i) //��������ʱ�����ȫ�ֱ�������Ϊ��������Ҫ���Ѻܶ�ʱ�䡣
{
	 //�ҵ���һ������m��Ԫ��
	if (num[num.size() - 1] <= m) return num.size();
	int left, right,mid;
	left = i + 1;
	right = num.size() - 1;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (num[mid] > m)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	int N, p;
	cin >> N >> p;
	int i,tmp;
	int ans = 1;
	for (i = 0; i < N; i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	int index;
	for (i = 0; i < N; i++)
	{
		//index = upper_bound(num.begin() + i + 1, num.end(), (long long)num[i] * p) - num.begin();
		index = binarysearch((long long)num[i] * p, i);
		ans = max(ans, index - i);
	}
	cout << ans << endl;
	return 0;
}