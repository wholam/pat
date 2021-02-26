//快速排序
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int partition(int A[], int left, int right);//范围划分中点位置
int randpartition(int A[], int left, int right);
void quickSort(int A[], int left, int right);
int main()
{
	int A[] = { 35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55 };
	srand((unsigned)time(NULL));
	quickSort(A, 0, 10);
	for (int i = 0; i < 11; i++)
		cout << A[i] << " ";
	return 0;
}
int partition(int A[], int left, int right)
{
	int temp = A[left];
	int i, j;
	i = left; j = right;
	while (i < j)
	{
		while (i < j && A[j] > temp)
			j--;
		A[i] = A[j];
		while (i < j && A[i] <= temp)
			i++;
		A[j] = A[i];
	}
	A[i] = temp;
	return i;
}
int randpartition(int A[], int left, int right)
{
	int p = rand() % (right - left + 1) + left;
	swap(A[p], A[left]);
	int temp = A[left];
	int i, j;
	i = left; j = right;
	while (i < j)
	{
		while (i < j && A[j] > temp)
			j--;
		A[i] = A[j];
		while (i < j && A[i] <= temp)
			i++;
		A[j] = A[i];
	}
	A[i] = temp;
	return i;
}
void quickSort(int A[], int left, int right)
{
	if (left < right)
	{
		int pos = randpartition(A, left, right);
		quickSort(A, left, pos - 1);
		quickSort(A, pos + 1, right);
	}
}