#include<iostream>
#include<string>
using namespace std;

//int eachdigit(int N, int digit[101]);
//int main()
//{
//	int digit[101] = { 0 },length=0,sum=0;
//	int long long N;
//	string eng[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
//	cin >> N;
//	length = eachdigit(N, digit);
//	for (int i = 0; i < length; i++)
//		sum += digit[i];
//	length = eachdigit(sum, digit);
//	int temp;
//	for (int i = length-1; i>=0; i--)
//	{
//		temp = digit[i];
//		if (i != 0)
//			cout << eng[temp] << " ";
//		else
//			cout << eng[temp];
//	}
//	return 0;
//}
int eachdigit(int N, int digit[101])
{
	int i=0;
	if (N == 0)
	{
		digit[i] = 0;
		i++;
		return i;
	}
	while (N != 0)
	{
		digit[i] = N % 10;
		i++;
		N = N / 10;
	}
	return i;
}

int main()
{
	char digit[101] = { '\0' };
	string eng[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	cin >> digit;
	int len = strlen(digit);
	int sum = 0;
	int temp;
	for (int i = 0; i < len; i++)
	{
		temp = digit[i] - '0';
		sum += temp;
	}
	int dig[101] = { 0 };
	int len2 = eachdigit(sum, dig);
	for (int i = len2-1; i>=0; i--)
	{
		temp = dig[i];
		if (i != 0)
			cout << eng[temp] << " ";
		else
			cout << eng[temp];
	}
	return 0;
}