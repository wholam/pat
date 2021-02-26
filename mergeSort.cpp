#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//递归写法
void mergeSort(int A[], int left, int right);
void merge(int A[], int L1, int R1, int L2, int R2);
//非递归写法
void mergeSort1(int A[], int n);//n为元素个数
int main()
{
	int A[] = { 66,12,33, 57, 54, 64, 29, 27,18 };
	mergeSort1(A, 9);
	for (int i = 0; i < 9; i++)
		cout << A[i] << " ";
	return 0;
}
void mergeSort(int A[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, mid+1, right);
	}
}
void merge(int A[], int L1, int R1, int L2, int R2)
{
	vector<int> tmp;
	int i, j;
	i = L1; j = L2;
	while (i <= R1 && j <= R2)
	{
		if (A[i] <= A[j])
			tmp.push_back(A[i++]);
		else
			tmp.push_back(A[j++]);
	}
	while (i <= R1)
		tmp.push_back(A[i++]);
	while (j <= R2)
		tmp.push_back(A[j++]);
	for (i = 0; i < tmp.size(); i++)
		A[i + L1] = tmp[i];
}
void mergeSort1(int A[], int n)
{
	int L1, R1, L2, R2;
	for (int step = 2; step / 2 < n; step *= 2)//step/2是两两归并时每个组的元素个数
	{
		for (int i = 0; i < n; i += step)
		{
			L1 = i; R1 = i - 1 + step / 2;
			L2 = R1 + 1; R2 = min(n - 1, i + step - 1);
			if (R1 < R2)
				merge(A, L1, R1, L2, R2);//可以替换成sort函数
		}
	}
}